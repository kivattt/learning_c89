#include <stdlib.h>
#include <string.h>

/* FIXME: Arbitrary types, not just float. Let the user allocate their stuff. */
struct Vector {
	float *data;
	size_t length;
	size_t capacity;
};

void our_realloc(struct Vector *v, size_t new_length) {
	float *new_ptr = (float*)malloc(new_length * 4);
	memcpy(new_ptr, v->data, v->length * 4);
	free(v->data);
	v->data = new_ptr;
}

void vector_make(struct Vector *v) {
	v->length = 0;
	v->capacity = 1;
	v->data = (float*)malloc(v->capacity * 4);
}

void vector_free(struct Vector *v) {
	free(v->data);
}

void vector_push_back(struct Vector *v, float element) {
	if (v->length + 1 > v->capacity) {
		v->capacity *= 2; /* FIXME: Copy Go's growth function */
		our_realloc(v, v->capacity);
	}

	v->data[v->length] = element;
	v->length += 1;
}

void vector_remove_last(struct Vector *v) {
	if (v->length > 0) {
		v->length -= 1;
	}
}

void vector_shrink_to_fit(struct Vector *v) {
	v->capacity = v->length;
	our_realloc(v, v->capacity);
}

void vector_print(struct Vector *v) {
	size_t i;

	if (v->length == 0) {
		printf("<empty vector>\n");
		return;
	}

	for (i = 0; i < v->length; i++) {
		printf("%f", v->data[i]);
		if (i != v->length -1) {
			printf(",");
		}
	}
	printf("\n");
}
