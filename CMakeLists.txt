cmake_minimum_required(VERSION 3.20)
project(booklet LANGUAGES CXX)

# Enforce C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Define the executable target (assuming your source file is named booklet.cc)
add_executable(booklet src/booklet.cc)
