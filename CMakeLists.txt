project(fastat)
cmake_minimum_required(VERSION 2.8.0)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(src/)
file(
	GLOB_RECURSE
	source_files
	src/*
)

add_executable(
        fastat
        ${source_files}
)
