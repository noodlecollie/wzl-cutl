# Chosen minimum CMake version chosen based on https://www.scivision.dev/cmake-changelog/
cmake_minimum_required(VERSION 3.24)
LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

project(wzl-cutl LANGUAGES C CXX)

option(BUILD_SHARED_LIBS "If set, builds a shared library. If not set, builds a static library." FALSE)
option(COMPILE_WARNING_AS_ERROR "If set, any compiler warnings are treated as errors." TRUE)

set(GENERATED_HEADER_DIR "${CMAKE_CURRENT_BINARY_DIR}/generated_headers")
set(GENERATED_EXPORT_HEADER "${GENERATED_HEADER_DIR}/wzl_cutl/libexport.h")

include(generate_export_header_template)
generate_export_header_template(
	TARGET wzl-cutl
	OUTPUT ${GENERATED_EXPORT_HEADER}
	PRODUCER_DEFINE WZL_CUTL_PRODUCER
)

add_library(wzl-cutl
	${GENERATED_EXPORT_HEADER}

	include/wzl_cutl/libloader.h
	include/wzl_cutl/memory.h
	include/wzl_cutl/platform_defs.h
	include/wzl_cutl/string.h

	src/wzl_cutl_/common/memory/memory_impl.h
	src/wzl_cutl_/common/memory/memory_impl.c
	src/wzl_cutl_/common/string/string_impl.c

	$<$<BOOL:WIN32>:src/wzl_cutl_/windows/libloader/libloader_impl.c>
	$<$<BOOL:WIN32>:src/wzl_cutl_/windows/winapi_min.h>
)

target_compile_definitions(wzl-cutl
	PRIVATE
	WZL_CUTL_PRODUCER
)

if(MSVC)
	target_compile_definitions(wzl-cutl PRIVATE
		/W4
	)
elseif(GNU OR Clang)
	target_compile_definitions(wzl-cutl PRIVATE
		-Wall
		-Wextra
		-pedantic
	)
else()
	message(FATAL_ERROR "Unsupported compiler")
endif()

target_include_directories(wzl-cutl
	PUBLIC
	include
	${GENERATED_HEADER_DIR}

	PRIVATE
	src
)
