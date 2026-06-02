cmake_minimum_required(VERSION 3.14)
project(MiniBank LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Włączamy ostrzeżenia kompilatora
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

include_directories(include)

add_executable(minibank
    src/main.cpp
    src/Account.cpp
    src/Bank.cpp
    src/CLI.cpp
)
