cmake_minimum_required(VERSION 3.0)

# Set the project name
project(VAE-Addon)
set(CMAKE_CXX_STANDARD 20)
# include the header files
include_directories(./include)

# Add an executable
add_executable(VAE-Addon ./src/main.cpp)
