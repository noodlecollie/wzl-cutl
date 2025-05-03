#include <direct.h>
#include <stdlib.h>
#include <string.h>
#include "wzl_cutl/filesystem.h"
#include "wzl_cutl/math.h"
#include "wzl_cutl/string.h"
#include "wzl_cutl_/common/memory/memory_impl.h"
#include "wzl_cutl_/windows/winapi_min.h"

// Limit this to the size of a DWORD, for Windows' sake.
#define MAX_ALLOC_PATH (size_t)((DWORD)2048)

WZL_CUTL_PUBLIC(char*) wzl_get_cwd(char* buffer, size_t buffer_size)
{
	return wzl_strdup_if_delegated(_getcwd(buffer, buffer_size < INT_MAX ? (int)buffer_size : INT_MAX));
}

WZL_CUTL_PUBLIC(char*) wzl_get_executable_path(char* buffer, size_t buffer_size)
{
	if ( buffer )
	{
		GetModuleFileNameA(NULL, buffer, buffer_size < UINT_MAX ? (DWORD)buffer_size : UINT_MAX);
		return NULL;
	}

	char* temp_buffer = NULL;
	DWORD temp_buffer_size = WZL_MAX(MAX_PATH / 2, 1);
	DWORD last_error = 0;

	do
	{
		if ( temp_buffer )
		{
			free(temp_buffer);
		}

		temp_buffer_size = WZL_MAX(temp_buffer_size * 2, MAX_ALLOC_PATH);
		temp_buffer = wzl_malloc_(temp_buffer_size);

		GetModuleFileNameA(NULL, temp_buffer, (DWORD)temp_buffer_size);
		last_error = GetLastError();
	}
	while ( last_error == ERROR_INSUFFICIENT_BUFFER && temp_buffer_size < MAX_ALLOC_PATH );

	if ( last_error == ERROR_INSUFFICIENT_BUFFER )
	{
		// Don't leak this buffer if we failed the process.
		wzl_free_(temp_buffer);
		return NULL;
	}
	else
	{
		return temp_buffer;
	}
}

WZL_CUTL_PUBLIC(bool) wzl_file_exists(const char* native_path)
{
	if ( !native_path || !(*native_path) )
	{
		return false;
	}

	const DWORD attributes = GetFileAttributesA(native_path);
	return attributes != INVALID_FILE_ATTRIBUTES && !(attributes & FILE_ATTRIBUTE_DIRECTORY);
}

WZL_CUTL_PUBLIC(bool) wzl_directory_exists(const char* native_path)
{
	if ( !native_path || !(*native_path) )
	{
		return false;
	}

	const DWORD attributes = GetFileAttributesA(native_path);
	return attributes != INVALID_FILE_ATTRIBUTES && (attributes & FILE_ATTRIBUTE_DIRECTORY);
}
