void write_data_to_file(const char *filename, void *data, size_t num_bytes) {
	FILE *output_file = fopen(filename, "wb");
	fwrite(data, num_bytes, 1, output_file);
	fclose(output_file);
}

void print_bits(void *ptr, int bytes) {
	int i = 0;
	int j = 0;
	unsigned char number = 0;
	for (i = 0; i < bytes; i++) {
		number = ((unsigned char*)ptr)[i];
		/*number = *(((unsigned char*)ptr)[i]);*/

		for (j = 0; j < 8; j++) {
			putchar('0' + ((number >> j) & 1));
		}
	}

	putchar('\n');
}

/*
 * nanosleep() is not in C89 ...
 *
void sleep_millis(int milliseconds) {
	struct timespec request;
	request.tv_sec = 0;
	request.tv_nsec = milliseconds * 1000;
	while (nanosleep(&request, &request) == -1) continue;
}
*/
