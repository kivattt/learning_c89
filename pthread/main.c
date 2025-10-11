#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

#include "raylib/include/raylib.h"
#define WIDTH 1280
#define HEIGHT 720

void *entry() {
	printf("hello");
	return NULL;
}

int main() {
	pthread_t t;
	if (pthread_create(&t, NULL, &entry, NULL)) {
		printf("Failed to create thread\n");
		return 1;
	}

	sleep(1);
	printf(" world!\n");

	if (pthread_join(t, NULL)) {
		printf("Couldn't join thread\n");
		return 1;
	}

	/*SetConfigFlags({.});*/
	InitWindow(WIDTH, HEIGHT, "ui test");
	SetTargetFPS(60);

	while (!WindowShouldClose()) {
		BeginDrawing();
		DrawText("hello world", 190, 200, 20, LIGHTGRAY);
		EndDrawing();
	}

	return 0;
}
