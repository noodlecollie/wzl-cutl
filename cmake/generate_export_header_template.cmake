function(generate_export_header_template)
	set(options STATIC SHARED)
	set(oneValueArgs TARGET OUTPUT IS_STATIC)
	set(multiValueArgs "")

	cmake_parse_arguments(EXPORTHEADER "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(EXPORTHEADER_STATIC AND EXPORTHEADER_SHARED)
		message(FATAL_ERROR "Cannot specify both STATIC and SHARED in this function invocation")
	endif()

	string(TOUPPER "${EXPORTHEADER_TARGET}" EXPORTHEADER_TARGET_UPPERCASE)
	string(REGEX REPLACE "[^A-Z0-9_]" "_" EXPORTHEADER_TARGET_UPPERCASE "${EXPORTHEADER_TARGET_UPPERCASE}")

	# Prepend a prefix if the string begins with a number
	if("${EXPORTHEADER_TARGET_UPPERCASE}" MATCHES "^[0-9]")
		set(EXPORTHEADER_TARGET_UPPERCASE "_${EXPORTHEADER_TARGET_UPPERCASE}")
	endif()

	if(EXPORTHEADER_STATIC)
		message(STATUS "EXPORTHEADER_STATIC WAS SET")
		set(EXPORTHEADER_STATIC_VAL 1)
	elseif(EXPORTHEADER_SHARED)
		message(STATUS "EXPORTHEADER_SHARED WAS SET")
		set(EXPORTHEADER_STATIC_VAL 0)
	else()
		if(BUILD_SHARED_LIBS)
			message(STATUS "BUILD_SHARED_LIBS WAS SET")
			set(EXPORTHEADER_STATIC_VAL 0)
		else()
			message(STATUS "BUILD_SHARED_LIBS WAS NOT SET")
			set(EXPORTHEADER_STATIC_VAL 1)
		endif()
	endif()

	configure_file("${CMAKE_CURRENT_FUNCTION_LIST_DIR}/export_header_template.in" "${EXPORTHEADER_OUTPUT}")
	target_compile_definitions(${EXPORTHEADER_TARGET} PRIVATE "${EXPORTHEADER_TARGET_UPPERCASE}_PRODUCER")
endfunction()
