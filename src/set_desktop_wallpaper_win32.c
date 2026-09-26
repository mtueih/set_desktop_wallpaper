#include "set_desktop_wallpaper/set_desktop_wallpaper.h"
#include <windows.h>

#ifdef DEBUG
#include <stdio.h>
#endif

/* 设置桌面壁纸（单张图片）。 */
bool set_desktop_wallpaper(const char *const image_file_path)
{
	if (!SystemParametersInfoA(
			SPI_SETDESKWALLPAPER,
			0,
			(void *)image_file_path,
			SPIF_UPDATEINIFILE | SPIF_SENDCHANGE))
	{
#ifdef DEBUG
		const DWORD err_code = GetLastError();
		fprintf(
			stderr, "[%s | %s]: [Error]: SystemParametersInfoA() failed with error %lu\n",
			__FILE__, __func__, err_code);
#endif
		return false;
	}

	return true;
}

/* 设置桌面壁纸（单张图片）（宽字符串版本）。 */
bool set_desktop_wallpaper_w(const wchar_t *const image_file_path)
{
	if (!SystemParametersInfoW(
			SPI_SETDESKWALLPAPER,
			0,
			(void *)image_file_path,
			SPIF_UPDATEINIFILE | SPIF_SENDCHANGE))
	{
#ifdef DEBUG
		const DWORD err_code = GetLastError();
		fprintf(
			stderr, "[%s | %s]: [Error]: SystemParametersInfoW() failed with error %lu\n",
			__FILE__, __func__, err_code);
#endif
		return false;
	}

	return true;
}
