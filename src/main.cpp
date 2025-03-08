#include <asio.hpp>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

#define PORT 6377

std::unordered_map<std::string, std::string> redis;
std::mutex mutex;

void printVector(const std::vector<std::string> &words) {
  for (const std::string &word : words) {
    std::cout << word << " ";
  }
  std::cout << std::endl;
}

void handle_client(asio::ip::tcp::socket socket) {
  asio::streambuf buffer;

  try {
    while (true) {
      // Read as much data as available (at least 1 byte)
      size_t bytes_transferred =
          asio::read(socket, buffer, asio::transfer_at_least(1));

      // Extract data from the buffer
      std::istream input_stream(&buffer);
      std::string command;
      std::vector<std::string> command_parts;

      // Read all lines from the stream
      for (int i = 0; std::getline(input_stream, command); i++) {
        if (!command.empty() && command.back() == '\r') {
          command.pop_back(); // Remove trailing '\r'
        }
        command_parts.insert(command_parts.end(), command);
      }

      printVector(command_parts);
      std::transform(command_parts[2].begin(), command_parts[2].end(),
                     command_parts[2].begin(), ::tolower);

      std::string response;
      if (command_parts[2] == "set") {
        mutex.lock();
        redis[command_parts[4]] = command_parts[6];
        mutex.unlock();
        response = "+OK\r\n";
      } else if (command_parts[2] == "get" &&
                 redis.find(command_parts[4]) != redis.end()) {
        mutex.lock();
        response = "+" + redis[command_parts[4]] + "\r\n";
        mutex.unlock();
      } else if (command_parts[2] == "ping") {
        response = "+PONG\r\n";
      } else if (command_parts[2] == "del") {
        mutex.lock();
        redis.erase(command_parts[6]);
        mutex.unlock();
        response = ":1\r\n";
      } else {
        response = "-ERR unknown command or internal server error\r\n";
      }
      asio::write(socket, asio::buffer(response));
    }
  } catch (const std::exception &e) {
    std::cout << "Failure: Connection closed or error occurred." << std::endl;
    std::cerr << "Error: " << e.what() << std::endl;
  }
}

int main() {
  try {
    asio::io_context io_context;
    asio::ip::tcp::acceptor acceptor(
        io_context, asio::ip::tcp::endpoint(asio::ip::tcp::v4(), PORT));

    std::cout << "Server is listening on port 6377...." << std::endl;
    while (true) {
      asio::ip::tcp::socket socket(io_context);
      acceptor.accept(socket);
      std::cout << "Client connected" << std::endl;
      std::thread(handle_client, std::move(socket)).detach();
    }
  } catch (const std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }

  return 0;
}
