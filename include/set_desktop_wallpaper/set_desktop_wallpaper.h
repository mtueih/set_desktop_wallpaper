#ifndef SET_DESKTOP_WALLPAPER_H
#define SET_DESKTOP_WALLPAPER_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
namespace set_desktop_wallpaper
{
	extern "C"
	{
#endif

		/**
		 * @brief 设置桌面壁纸（单张图片）。
		 *
		 * @param[in] image_file_path
		 * 包含目标图片路径（不支持相对路径）的单个字符串（应使用系统代码页编码）。
		 *
		 * @return
		 * 是否设置成功，设置成功返回 true，否则返回 false。
		 */
		bool set_desktop_wallpaper(const char *image_file_path);

		/**
		 * @brief 设置桌面壁纸（单张图片）（宽字符串版本）。
		 *
		 * @param[in] image_file_path
		 * 包含目标图片路径（不支持相对路径）的单个字符串（应使用系统宽字符编码）。
		 *
		 * @return
		 * 是否设置成功，设置成功返回 true，否则返回 false。
		 */
		bool set_desktop_wallpaper_w(const wchar_t *image_file_path);

#ifdef __cplusplus
	}
}
#endif

#endif
