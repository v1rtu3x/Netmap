# Netmap

A simple IPv4 TCP connect() scanner written in C.  
This project is for **educational purposes only** — do not use it to scan networks you do not own or have explicit permission to test.

---

## Features
- Naive TCP connect scanning using sockets
- Works on Linux/Unix environments
- Configurable target port and optional IP range
- Prints banners/headers from services that respond

---

## Build
Make sure you have GCC installed. Then:

```bash
make

## Usage
Run without IP range (single input via stdin):

./nm-naive 80

Type an IP address and press Enter.

Run with range:

./nm-naive 80 192.168.0.1 192.168.0.254


This scans all addresses from 192.168.0.1 through 192.168.0.254 on port 80.

File Overview

nm-naive.c / nm-naive.h — main scanner logic and function prototypes

netmap.h — common includes and typedefs