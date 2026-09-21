#include "mtueih/set_desktop_wallpaper.h"
#include <windows.h>

/* 设置桌面壁纸（单张图片）。 */
bool set_desktop_wallpaper(const char *const image_file_path) {
	return SystemParametersInfoA(
		SPI_SETDESKWALLPAPER,
		0,
		(void*)image_file_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}

/* 设置桌面壁纸（单张图片）（宽字符串版本）。 */
bool set_desktop_wallpaper_w(const wchar_t *const image_file_path) {
	return SystemParametersInfoW(
		SPI_SETDESKWALLPAPER,
		0,
		(void*)image_file_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}
