#!/usr/bin/env python3

import socket
import sys

if len(sys.argv) < 3:
    print("Usage: {} <ip> <port>".format(sys.argv[0]))
    exit(1)

sock = socket.socket()
sock.connect((sys.argv[1], int(sys.argv[2])))
print(sock.recv(4096).decode())
