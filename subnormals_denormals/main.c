#include <stdio.h>

#include "../lib.h"

void deez(float *x) {
	/**x = *x + *x;
	*x = *x / 2;*/

	__m128 val = _mm_set1_ps(*x);
	__m128 two = _mm_set_ps(2.0);
	*x = _mm_fmadd_ss(val, two, val);
	return;
}

int main() {
	float x = 1.17549435082228750796873653722224568e-38F;
	unsigned int y = 1056964608;
	print_bits(&y, 4);

	printf("sizeof(x): %ld\n", sizeof(x));

	print_bits(&x, 4);
	x = x + x;
	print_bits(&x, 4);
	x = x / 2;
	print_bits(&x, 4);
	deez(&x);
	print_bits(&x, 4);

	return 0;
}
