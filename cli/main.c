#include <stdio.h>
#include "set_desktop_wallpaper.h"

int main(int argc, char *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "Usage: %s [image_file_path].\n", argv[0]);
		return 1;
	}

	if (!set_desktop_wallpaper(argv[1])) {
		fprintf(stderr, "Failed to set desktop wallpaper!\n");
		return 1;
	}

	printf("Desktop Wallpaper Successfully Set.\n");
	return 0;
}
