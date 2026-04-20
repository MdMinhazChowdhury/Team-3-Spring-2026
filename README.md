# Team-3-Spring-2026

# PokerSim
## Folder Structure
PokerSim/
    src/            # C++ source files
    include/        # Header files
    CMakeLists.txt  # CMake build configuration
    .devcontainer/  # Docker + VS Code development environment
## Build inside Dev Container (recommended) requires Docker Destop and VScode
1. Open repo in VS Code
2. When prompted, "Reopen in Container"
3. Build with:
   cmake -S . -B build
   cmake --build build

## Build without Dev Container
Requires:
- CMake 3.10+
- C++17 compiler

mkdir build
cd build
cmake ..
cmake --build .