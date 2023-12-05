#include "wzl_cutl/filesystem.h"
#include "wzl_cutl_/windows/winapi_min.h"

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
