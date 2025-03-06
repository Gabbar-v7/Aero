# Aero Redis Server

A lightweight, high-performance C++ Redis server prototype built using **ASIO** for asynchronous networking. This project demonstrates how to build with a Redis server using modern C++ and asynchronous I/O.

## Features

- **Asynchronous Communication**: Leverages ASIO for non-blocking I/O operations.
- **Simple API**: Easy-to-use interface for sending Redis commands and receiving responses.
- **Cross-Platform**: Works on Windows, macOS, and Linux.
- **Dependency-Free**: Only requires ASIO (header-only library).

## Prerequisites

- **C++ Compiler**: Supports C++23 (e.g., GCC, Clang, MSVC).
- **CMake**: Version 3.10 or higher.
- **Git**: For cloning the repository and managing submodules.

## Installation

### 1. Clone the Repository

Clone the repository and its submodules:

```bash
git clone --recurse-submodules https://github.com/Gabbar-v7/Aero.git
cd Aero
```

### 2. Build the Project

Use CMake to build the project:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

### 3. Run the Executable

After building, run the executable:

```bash
./AeroRedisServer
```

## Usage

### Basic Example

Here’s an example of how to interact with Aero Redis Server using Redis Client:

```bash
 Aero ❯ master* ❯ redis-cli -p 6377
    127.0.0.1:6377> set name Gabbar
    OK
    127.0.0.1:6377>
    127.0.0.1:6377> get name
    Gabbar
    127.0.0.1:6377> ping
    PONG
    127.0.0.1:6377>
```

### Supported Commands

- `SET key value`: Set a key-value pair.
- `GET key`: Get the value of a key.
- `DEL key`: Delete a key.
- `PING`: Check if the server is alive.

**Note:** AeroRedisServer runs on default port 6377

## Project Structure

```
Aero/
├── CMakeLists.txt            # CMake build configuration
├── README.md                 # Project documentation
│
├── src/                      # Source files
│     └── main.cpp            # Starting point
│
└── libs/                     # Third-party dependencies
      └── asio/               # ASIO library (submodule)
```

## Dependencies

- **[ASIO](https://github.com/chriskohlhoff/asio)**: A cross-platform C++ library for network and low-level I/O programming.

## Contributing

Contributions are welcome! If you’d like to contribute, please follow these steps:

1. Fork the repository.
2. Create a new branch for your feature or bugfix.
3. Make your changes and test them.
4. Submit a pull request with a detailed description of your changes.

For more information, see the [CONTRIBUTING.md](CONTRIBUTING.md) file.

## License

This project is licensed under the **MIT License**. See the [LICENSE](LICENSE) file for details.

## Acknowledgments

- **ASIO**: For providing a powerful and easy-to-use networking library.
- **Redis**: For being an awesome in-memory data store.

## Issues

For questions or feedback, feel free to reach out:

- **GitHub Issues**: [https://github.com/Gabbar-v7/Aero/issues](https://github.com/Gabbar-v7/Aero/issues)
