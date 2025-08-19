#include <stdio.h>
#include <dirent.h>

#include "string.c"

int main() {
	DIR *directory;
	struct dirent *dir_entry;

	directory = opendir(".");

	while ((dir_entry = readdir(directory))) {
		const char *filename = dir_entry->d_name;

		if (str_eq(".", filename)) {
			continue;
		}

		if (str_eq("..", filename)) {
			continue;
		}

		printf("%s\n", filename);
	}

	return 0;
}
