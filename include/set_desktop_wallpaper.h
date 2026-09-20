#ifndef SET_DESKTOP_WALLPAPER_H
#define SET_DESKTOP_WALLPAPER_H

#include <stdbool.h>
#include <stddef.h>


#ifdef __cplusplus
extern "C" {
#endif


bool set_desktop_wallpaper(const char *image_file_path);

bool set_desktop_wallpaper_w(const wchar_t *image_file_path);


#ifdef __cplusplus
}
#endif


#endif
