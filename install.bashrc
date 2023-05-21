#!/bin/bash
apt-get update
apt-get install -y build-essential

make clean
make

chmod +x my_binary

echo "Installation complete."
