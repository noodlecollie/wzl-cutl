#include <dirent.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "wzl_cutl/filesystem.h"
#include "wzl_cutl/math.h"
#include "wzl_cutl_/common/memory/memory_impl.h"

WZL_CUTL_PUBLIC(char*) wzl_get_cwd(char* buffer, size_t buffer_size)
{
	bool self_allocated_buffer = false;
	char* out = getcwd(buffer, buffer_size);

	// "As an extension to the POSIX.1-2001 standard, glibc's getcwd()
	// allocates the buffer dynamically using malloc(3) if buf is NULL."
	// Simulate this behaviour if it didn't happen.
	if ( !out && !buffer )
	{
		char* temp_buffer = NULL;
		size_t temp_buffer_size = WZL_MAX(buffer_size, 1);

		do
		{
			if ( temp_buffer )
			{
				free(temp_buffer);
			}

			temp_buffer_size = WZL_MAX(temp_buffer_size * 2, PATH_MAX);
			temp_buffer = wzl_malloc_(temp_buffer_size);
			self_allocated_buffer = true;

			// Out should equal temp_buffer when the call succeeds.
			out = getcwd(temp_buffer, temp_buffer_size);
		}
		while ( !out && errno == ERANGE && temp_buffer_size < PATH_MAX );

		if ( !out && temp_buffer )
		{
			// Don't leak this buffer if we failed the process.
			wzl_free_(temp_buffer);
		}
	}

	return self_allocated_buffer ? out : wzl_strdup_if_delegated(out);
}

WZL_CUTL_PUBLIC(char*) wzl_get_executable_path(char* buffer, size_t buffer_size)
{
	ssize_t result = 0;

	if ( buffer )
	{
		result = readlink("/proc/self/exe", buffer, buffer_size);
		return NULL;
	}

	char* temp_buffer = NULL;
	size_t temp_buffer_size = WZL_MAX(buffer_size, 1);
	bool wrote_successfully = false;

	do
	{
		if ( temp_buffer )
		{
			free(temp_buffer);
		}

		temp_buffer_size = WZL_MAX(temp_buffer_size * 2, PATH_MAX);
		temp_buffer = wzl_malloc_(temp_buffer_size);

		result = readlink("/proc/self/exe", buffer, buffer_size);

		wrote_successfully =
			result > 0 && ((size_t)result < temp_buffer_size || temp_buffer[temp_buffer_size - 1] == '\0');
	}
	while ( result > 0 && (size_t)result == temp_buffer_size && temp_buffer[temp_buffer_size - 1] != '\0' &&
			temp_buffer_size < PATH_MAX );

	if ( !wrote_successfully && temp_buffer )
	{
		// Don't leak this buffer if we failed the process.
		wzl_free_(temp_buffer);
	}

	return temp_buffer;
}

WZL_CUTL_PUBLIC(bool)
wzl_file_exists(const char* native_path)
{
	if ( !native_path || !(*native_path) )
	{
		return false;
	}

	return access(native_path, F_OK) != -1;
}

WZL_CUTL_PUBLIC(bool) wzl_directory_exists(const char* native_path)
{
	if ( !native_path || !(*native_path) )
	{
		return false;
	}

	bool result = false;
	DIR* dir = opendir(native_path);

	if ( dir != NULL )
	{
		result = true;
		closedir(dir);
	}

	return result;
}
