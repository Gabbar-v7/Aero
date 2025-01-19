#include <asio.hpp>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>

#define PORT 6377

std::unordered_map<std::string, std::string> redis;
std::mutex mutex;

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
      std::ostringstream full_command;

      // Read all lines from the stream
      std::cout << "command" << command << std::endl;
      while (std::getline(input_stream, command)) {
        if (!command.empty() && command.back() == '\r') {
          command.pop_back(); // Remove trailing '\r'
        }
        full_command << command << " ";
      }

      // Process the full command
      std::string full_command_str = full_command.str();
      std::cout << "Received command: " << full_command_str << std::endl;

      // Prepare a response
      std::string response, key, value;
      if (full_command_str.find("set ") == 6) {
        mutex.lock();
        //        redis[key] = value;
        mutex.unlock();
        response = "+OK\r\n"; // RESP Simple String response for success
      } else if (full_command_str.find("get ") == 6) {
        mutex.lock();
        // value = redis[key];
        mutex.unlock();
        response = "$-1\r\n"; // RESP Null Bulk String (no data found)
      } else if (full_command_str.find("ping ") != std::string::npos) {
        response = "+PONG\r\n";
      } else {
        response = "-ERR unknown command\r\n";
      }

      // Send the response to the client
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
