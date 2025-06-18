cmake_minimum_required(VERSION 3.31)
project(soundboard)

add_executable(soundboard src/main.cpp)

target_compile_options(soundboard PRIVATE "$<$<CXX_COMPILER_ID:MSVC>:/std:c++latest>")