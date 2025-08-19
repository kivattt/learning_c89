#include <immintrin.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

char alpha[] = "0123456789abcdef";

void print_hex(int number) {
	int i;
	ssize_t shouldBeOne;
	for (i = 0; i < 8; i++) {
		char *c = &alpha[(number >> (32 - 4*i)) & 0xF];
		shouldBeOne = write(1, c, 1);
		if (shouldBeOne != 1) {
			printf("epic fail\n");
		}
	}

	shouldBeOne = write(1, "\n", 1);
	if (shouldBeOne != 1) {
		printf("epic fail\n");
	}
}

int main() {
	byte *data = (byte*)malloc(256);
	int i;
	int number = 0;

	for (i = 0; i < 256; i++) {
		data[i] = (byte)i;
	}

	number = *((int*)data);
	print_hex(number);

	for (i = 0; i < 256 / 4; i++) {
		number |= *((int*)data+i);
	}

	printf("%d\n", number);

	free(data);
	return 0;
}
