FROM mcr.microsoft.com/devcontainers/cpp:latest

# Install extra tools if needed
RUN apt-get update && apt-get install -y \
    cmake \
    gdb \
    && rm -rf /var/lib/apt/lists/*
RUN apt-get update && apt-get install -y ninja-build

