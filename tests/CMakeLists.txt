option(CATCH_INSTALL_DOCS "" FALSE)
option(CATCH_INSTALL_EXTRAS "" FALSE)

add_subdirectory(Catch2)

add_executable(wzl-test
	src/String.cpp
)

target_include_directories(wzl-test PRIVATE src)

target_link_libraries(wzl-test PRIVATE
	Catch2::Catch2WithMain
	wzl-cutl
)

include(CTest)
include(Catch)
catch_discover_tests(wzl-test)
