#include <immintrin.h>
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

int main() {
	byte *data = (byte*)malloc(256);
	int i;
	int number = 0;

	for (i = 0; i < 256; i++) {
		data[i] = (byte)i;
	}

	for (i = 0; i < 256 / 4; i++) {
		number |= *((int*)data+i);
	}

	/*number = *((int*)data+0);*/
	/*number = _bswap(*((int*)data));*/

	printf("%d\n", number);

	free(data);
	return 0;
}
