cmake_minimum_required(VERSION 3.5.1)
project(TVS)
find_package(TVS)
add_executable ( main main.cpp  )
target_link_libraries ( main )