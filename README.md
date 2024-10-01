# Minitalk

This repository contains the **Minitalk** project, a part of the 42 curriculum. The objective of this project is to create a small data exchange program using UNIX signals. It involves implementing a server and a client that communicate by sending signals back and forth, representing characters of a message.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [Bonus Features](#bonus-features)
- [Contributing](#contributing)
- [License](#license)

## Overview

The **Minitalk** project demonstrates how to communicate between processes using **UNIX signals**. The project is divided into two programs:

- **Server**: A program that waits for signals and displays the message sent by the client.
- **Client**: A program that sends a string as a series of signals (SIGUSR1 and SIGUSR2) to the server.

The main goals of the project are to:

- Learn about UNIX signals and inter-process communication (IPC).
- Implement a reliable message-passing mechanism using signals.
- Handle signal interruptions and ensure data integrity.

## Project Structure

The project contains two main programs:

1. **Server**: Receives messages from the client via signals and displays them.
2. **Client**: Sends a string to the server using signals.

### Files:
- `server.c`: Contains the implementation of the server program.
- `client.c`: Contains the implementation of the client program.
- `minitalk.h`: Header file with function prototypes and necessary includes.
- `Makefile`: For compiling the server and client programs.

## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/aitomarabdeljalil/minitalk.git
   cd minitalk
   ```

2. Compile the project using the provided `Makefile`:

   ```bash
   make
   ```

   This will generate two executables:
   - `server`
   - `client`

## Usage

### Running the Server

To start the server, run the following command:

```bash
./server
```

This will print the **Process ID (PID)** of the server. Keep this PID to pass it to the client.

### Running the Client

To send a message from the client to the server, run the following command, replacing `<PID>` with the server's PID and `<message>` with the message you want to send:

```bash
./client <PID> "<message>"
```

Example:

```bash
./client 12345 "Hello, World!"
```

This will send the message `"Hello, World!"` to the server with PID `12345`, which will display it.

### Example of Complete Flow

1. Run the server:

   ```bash
   ./server
   ```

   Output:
   ```
   Server PID: 12345
   ```

2. From another terminal, run the client:

   ```bash
   ./client 12345 "42 Network Communication!"
   ```

   The server will output the following:

   ```
   42 Network Communication!
   ```

## How It Works

- The client sends the message one character at a time by converting each character into a sequence of **bits**.
- For each bit, the client sends a signal to the server:
  - **SIGUSR1**: Represents a bit `0`.
  - **SIGUSR2**: Represents a bit `1`.
- The server receives the signals and reconstructs the characters by interpreting the bit sequence.
- Once the message is completely sent, the server displays the full message.

### Signal Handling

- **Client**: 
  - Converts each character into binary (bit by bit) and sends the appropriate signal to the server.
- **Server**: 
  - Listens to the signals and assembles the characters by interpreting the incoming bits, then prints the full message.

## Bonus Features

The bonus part of the project includes:

- **Unicode Character Support**: Sending extended ASCII or Unicode characters.
- **Acknowledgment Signals**: The server sends a confirmation signal to the client after successfully receiving each character, ensuring data integrity.
- **Multiple Client Support**: The server can handle multiple clients sending messages concurrently.
- **Timeout Handling**: The server handles cases where no signal is received within a certain timeframe, allowing for more robust error handling.

To compile the bonus version:

```bash
make bonus
```

## Contributing

If you'd like to contribute to this project, feel free to fork the repository and submit a pull request. Contributions, bug reports, and feedback are always welcome!

### How to Contribute

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/new-feature`).
3. Commit your changes (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature/new-feature`).
5. Open a pull request.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
