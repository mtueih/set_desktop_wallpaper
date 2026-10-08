#include "set_desktop_wallpaper/set_desktop_wallpaper.h"
#include <windows.h>


#ifndef NDEBUG

#include <inttypes.h>
#include <stdio.h>

#define PUT_ERR_FMT(fmt, ...)                                                                      \
	fprintf(stderr, "[%s:%d] %s: " fmt "\n", __FILE__, __LINE__, __func__, __VA_ARGS__)

#endif


/* 设置桌面壁纸（单张图片）。 */
bool set_desktop_wallpaper(const char *const image_file_path) {
	if (!SystemParametersInfoA(SPI_SETDESKWALLPAPER, 0, (void *)image_file_path,
							   SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
#ifndef NDEBUG
		const DWORD err_code = GetLastError();
		PUT_ERR_FMT("SystemParametersInfoA() failed with error %" PRIu32 ".", err_code);
#endif
		return false;
	}

	return true;
}

/* 设置桌面壁纸（单张图片）（宽字符串版本）。 */
bool set_desktop_wallpaper_w(const wchar_t *const image_file_path) {
	if (!SystemParametersInfoW(SPI_SETDESKWALLPAPER, 0, (void *)image_file_path,
							   SPIF_UPDATEINIFILE | SPIF_SENDCHANGE)) {
#ifndef NDEBUG
		const DWORD err_code = GetLastError();
		PUT_ERR_FMT("SystemParametersInfoW() failed with error %" PRIu32 ".", err_code);
#endif
		return false;
	}

	return true;
}
