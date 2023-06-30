#!/bin/bash

# Check if apt is installed
if ! command -v apt &> /dev/null; then
    echo "apt package manager is not installed. Aborting."
    exit 1
fi

# Check if apt is up-to-date
echo "Checking apt version..."
current_version=$(apt list --upgradable 2>/dev/null | awk -F '/' '/\[upgradable\]/ {print $2; exit}')
if [[ -z "$current_version" ]]; then
    echo "apt is already up-to-date."
else
    echo "Updating apt..."
    apt update
    echo "apt updated to the latest version."
fi

# Continue with other commands here
# ...

# Build Docker image
docker build -t check-projects .

# Run Docker container
docker run -it -v "$(dirname "$(pwd)"):/home/school" check-projects

