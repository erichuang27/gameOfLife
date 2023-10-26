# Conways Game of Life

Conway's Game of Life, made for fun and testing.

## How to Use

Left click to add cell, Right Click to Remove cell, Space to iterate


   For a single-configuration generator (typically the case on Linux and macOS):
    
    cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
    cmake --build build
    

   For a multi-configuration generator (typically the case on Windows):
    
    cmake -S . -B build
    cmake --build build --config Release
    
