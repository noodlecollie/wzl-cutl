# Function: generate_export_header_template
# Generates a C/C++ header suitable for exporting symbols from
# shared or static libraries.
#
# See export_header_template.in for the structure that the
# exported header will follow.
#
# Parameters:
#
#   STATIC          - Set this if the target is a static library.
#   SHARED          - Set this if the target is a shared library.
#   TARGET          - Name of the target to generate the header for.
#   OUTPUT          - Output file where the header will be written.
#   PRODUCER_DEFINE - Preprocessor definition that distinguishes whether
#                     the target is being produced in the current build.
#                     This is expected to correspond to a private
#                     definition that is set separately on the target
#                     by the caller. If this definition is defined,
#                     the header facilitates marking symbols as
#                     dllexport on Windows; if it is not defined, the
#                     header marks these symbols as dllimport.
function(generate_export_header_template)
	set(options STATIC SHARED)
	set(oneValueArgs TARGET OUTPUT PRODUCER_DEFINE)
	set(multiValueArgs "")

	cmake_parse_arguments(EXPORTHEADER "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

	if(EXPORTHEADER_STATIC AND EXPORTHEADER_SHARED)
		message(FATAL_ERROR "Cannot specify both STATIC and SHARED in this function invocation")
	endif()

	if("${EXPORTHEADER_PRODUCER_DEFINE}" STREQUAL "")
		message(FATAL_ERROR "PRODUCER_DEFINE must be supplied to this function")
	endif()

	string(TOUPPER "${EXPORTHEADER_TARGET}" EXPORTHEADER_TARGET_UPPERCASE)
	string(REGEX REPLACE "[^A-Z0-9_]" "_" EXPORTHEADER_TARGET_UPPERCASE "${EXPORTHEADER_TARGET_UPPERCASE}")

	# Prepend a prefix if the string begins with a number
	if("${EXPORTHEADER_TARGET_UPPERCASE}" MATCHES "^[0-9]")
		set(EXPORTHEADER_TARGET_UPPERCASE "_${EXPORTHEADER_TARGET_UPPERCASE}")
	endif()

	if(EXPORTHEADER_STATIC)
		set(EXPORTHEADER_STATIC_VAL 1)
	elseif(EXPORTHEADER_SHARED)
		set(EXPORTHEADER_STATIC_VAL 0)
	else()
		if(BUILD_SHARED_LIBS)
			set(EXPORTHEADER_STATIC_VAL 0)
		else()
			set(EXPORTHEADER_STATIC_VAL 1)
		endif()
	endif()

	configure_file("${CMAKE_CURRENT_FUNCTION_LIST_DIR}/export_header_template.in" "${EXPORTHEADER_OUTPUT}")
endfunction()
