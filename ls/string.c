/* Returns 1 if the strings are equal. 0 otherwise. */
int str_eq(const char* str_1, const char* str_2) {
	int i = 0;

	while (1) {
		char a = str_1[i];
		char b = str_2[i];

		if (a != b) {
			return 0;
		}

		if (a == 0 || b == 0) {
			break;
		}

		i += 1;
	}

	return 1;
}
