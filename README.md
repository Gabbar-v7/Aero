# Aero  

## Overview  

**Aero** is a Redis clone server in development, written in C++. It uses ASIO for communication and implements the Redis Serialization Protocol (RESP) to communicate seamlessly with `redis-cli`. The server runs on the default port `6377` and is designed to mimic key functionalities of Redis, with plans for future enhancements.  


## Features  

- **Redis Compatibility**: Supports communication with `redis-cli` using RESP.  
- **ASIO for Networking**: Efficient and scalable networking layer built with ASIO.  
- **Default Port 6377**: Runs on the default port `6377`.  
- **Modular C++ Design**: Built for maintainability and extendability.  


## Getting Started  

### Prerequisites  

- **C++ Compiler**: Ensure you have a C++17 or newer compiler (e.g., g++, clang++).  
- **CMake**: Install CMake for building the project.  
- **Redis CLI**: Install Redis CLI to interact with the server.  

### Building the Project  

1. Clone the repository:  
   ```bash  
   git clone https://github.com/Gabbar-v7/Aero.git  
   ```  
2. Navigate to the project directory:  
   ```bash  
   cd Aero  
   ```  
3. Create a build directory and navigate into it:  
   ```bash  
   mkdir build && cd build  
   ```  
4. Configure the project using CMake:  
   ```bash  
   cmake ..  
   ```  
5. Build the project:  
   ```bash  
   make  
   ```  


## Running the Server  

After building the project, start the server:  
```bash  
./Aero  
```  

The server listens on the default port `6377`.  

### Testing with `redis-cli`  

To interact with the server using `redis-cli`:  
1. Start the Redis CLI:  
   ```bash  
   redis-cli -p 6377  
   ```  
2. Send commands (e.g., `PING`, `SET key value`, `GET key`).  



## Contributing  

Contributions are welcome! If you would like to contribute to Aero, please fork the repository and submit a pull request. Follow the project's coding standards and ensure that new functionality is tested.  


## License  

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.  