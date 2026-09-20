#include "set_desktop_wallpaper.h"
#include <windows.h>


bool set_desktop_wallpaper(const char *const image_file_path) {
	return SystemParametersInfoA(
		SPI_SETDESKWALLPAPER,
		0,
		(void*)image_file_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}

bool set_desktop_wallpaper_w(const wchar_t *image_file_path) {
	return SystemParametersInfoW(
		SPI_SETDESKWALLPAPER,
		0,
		(void*)image_file_path,
		SPIF_UPDATEINIFILE | SPIF_SENDCHANGE
	);
}
