void write_data_to_file(const char *filename, void *data, size_t num_bytes) {
	FILE *output_file = fopen(filename, "wb");
	fwrite(data, num_bytes, 1, output_file);
	fclose(output_file);
}
