# Minitalk

## 📌 Project Overview

Minitalk is a 42 school project that demonstrates interprocess communication using UNIX signals. The project consists of a **server** and a **client** program, where the client sends a string of characters to the server using **SIGUSR1** and **SIGUSR2** signals, which the server reconstructs and displays.

## 🚀 Features

- Implements **signal handling** using `sigaction()`.
- Transmits characters **bit by bit** using `SIGUSR1` and `SIGUSR2`.
- Supports **Unicode and emoji characters**.
- Handles **error cases**, including invalid PIDs.
- Implements **bonus features**, such as acknowledgment signals and improved performance.

## 📂 Project Structure

```
Minitalk/
├── src/
│   ├── client.c
│   ├── minitalk.h
│   ├── server.c
├── bonus/
│   ├── client_bonus.c
│   ├── server_bonus.c
├── includes/
├── libft/
│   ├── libft.a
├── Makefile
├── README.md
```

## 🛠️ Compilation

To compile the mandatory part:

```bash
make
```

To compile the bonus part:

```bash
make bonus
```

To clean object files:

```bash
make clean
```

To remove all compiled binaries and libraries:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

## 🏃‍♂️ Usage

1️⃣ **Run the server**:

```bash
./server
```

It will display:

```
Server PID: <PID>
```

2️⃣ **Run the client to send a message**:

```bash
./client <server_PID> "Hello, world!"
```

The server will then output:

```
Hello, world!
```

## 📝 Bonus Features

- **Acknowledgment Signal**: The server sends a signal back to the client after receiving a full character.
- **Unicode Support**: Allows sending and displaying Unicode characters and emojis.
- **Improved Performance**: Optimized to prevent unnecessary delays.

## 📜 Authors

- Developed as part of the 42 School curriculum.

