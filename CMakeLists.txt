# Chosen minimum CMake version chosen based on https://www.scivision.dev/cmake-changelog/
cmake_minimum_required(VERSION 3.24)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(wzl-cutl LANGUAGES C CXX)

option(BUILD_SHARED_LIBS "If set, builds a shared library. If not set, builds a static library." FALSE)

add_library(wzl-cutl
	include/wzl_cutl/dummy.h
	src/dummy.c
)

include(generate_export_header_template)
generate_export_header_template(TARGET wzl-cutl OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/generated_headers/wzl_cutl/libexport.h")

target_include_directories(wzl-cutl PUBLIC include ${CMAKE_CURRENT_BINARY_DIR}/generated_headers)
