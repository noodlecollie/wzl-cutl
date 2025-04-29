#include "wzl_cutl/string.h"
#include <catch2/catch_test_macros.hpp>
#include <vector>

TEST_CASE("strdup", "[string]")
{
	const char* firstString = "This is a string";
	char* secondString = wzl_strdup(firstString);

	REQUIRE(secondString);
	CHECK(strcmp(firstString, secondString) == 0);
	CHECK(firstString != secondString);

	free(secondString);
}

TEST_CASE("strcpy", "[string]")
{
	const char* sourceString = "This is quite a long source string that may get truncated";
	const size_t sourceStringLength = strlen(sourceString);

	char shortBuffer[8];

	CHECK(wzl_strcpy(nullptr, 0, nullptr) == 0);
	CHECK(wzl_strcpy(nullptr, 0, sourceString) == 0);
	CHECK(wzl_strcpy(shortBuffer, 0, sourceString) == 0);
	CHECK(wzl_strcpy(nullptr, 16, sourceString) == 0);

	const size_t shortCopyResult = wzl_strcpy(shortBuffer, sizeof(shortBuffer), sourceString);
	CHECK(shortCopyResult == sizeof(shortBuffer) - 1);
	CHECK(strcmp(shortBuffer, "This is") == 0);

	std::vector<char> longBuffer(sourceStringLength + 10, 'A');
	const size_t longCopyResult = wzl_strcpy(longBuffer.data(), longBuffer.size(), sourceString);

	CHECK(longCopyResult == sourceStringLength);
	CHECK(strcmp(longBuffer.data(), sourceString) == 0);

	std::vector<char> remainder(longBuffer.begin() + sourceStringLength, longBuffer.end());
	CHECK(remainder == std::vector<char>({'\0', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A'}));
}
