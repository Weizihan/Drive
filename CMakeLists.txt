cmake_minimum_required (VERSION 2.8)

project (demo)

set (SRC_LIST
    ./main.cpp
    ./framebuffer.cpp
    ./template_singleton.hpp
)
add_executable(main ${SRC_LIST})
