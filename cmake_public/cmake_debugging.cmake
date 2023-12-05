# Function: debug_gen_expr
# Creates a custom target called genexdebug, as per the CMake
# generator expression documentation. Build this target to see
# what the generator expression evaluates to.
#
# Parameters:
#
#   EXPRESSION - Generator expression that should be evaluated.
function(debug_gen_expr EXPRESSION)
	add_custom_target(genexdebug COMMAND ${CMAKE_COMMAND} -E echo "Generator expression: ${EXPRESSION}")
	message(STATUS "DEBUG: Please build custom target \"genexdebug\" to debug generator expression: ${EXPRESSION}")
endfunction()
