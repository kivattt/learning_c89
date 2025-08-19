#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main() {
	byte *data = (byte*)malloc(256);
	int i = 0;

	for (; i < 256; i++) {
		data[i] = (byte)i;
	}

	free(data);
	return 0;
}
