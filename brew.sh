#!/bin/bash

if ! command -v brew &> /dev/null; then
    echo "Homebrew not found. Installing Homebrew..."
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
else
    echo "Homebrew already installed."
fi

brew update

brew install gcc
brew install openssl

export MY_VARIABLE="my_value"

make clean
make

chmod +x my_binary

echo "Installation complete."
