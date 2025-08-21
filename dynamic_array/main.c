#include <stdio.h>
#include "vector.h"

int main() {
	struct Vector v;
	int i;
	int n = 5;
	vector_make(&v);

	for (i = 0; i < n; i++) {
		vector_push_back(&v, (float)i*1.5F);
		vector_print(&v);
	}

	for (i = 0; i < n; i++) {
		vector_remove_last(&v);
		vector_print(&v);
	}

	vector_free(&v);
	return 0;
}
