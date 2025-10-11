#include <stdio.h>
#include "include/raylib.h"

#define WIDTH 1280
#define HEIGHT 720

#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAX(a, b) ((a) > (b) ? (a) : (b))

//#define FONT_SIZE 

#define N_FONTS 24

int main() {
	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(WIDTH, HEIGHT, "ui test");
	SetTargetFPS(60);

	int fontSizes[N_FONTS];
	for (int i = 0; i < N_FONTS; i++) {
		int j = i+3;
		//fontSizes[i] = 10 + (j*j*j) / 40;
		fontSizes[i] = 10 + (j*j*j) / 30;
	}

	Font fonts[N_FONTS];

	int currFont = 0;

	for (int i = 0; i < N_FONTS; i++) {
		fonts[i] = LoadFontEx("fonts/Adwaita/AdwaitaSans-Regular.ttf", fontSizes[i], NULL, 0);
	}
	//Font font = LoadFontEx("fonts/Adwaita/AdwaitaSans-Regular.ttf", FONT_SIZE, NULL, 0);
	//Font font2 = LoadFontEx("fonts/Adwaita/AdwaitaSans-Regular.ttf", FONT_SIZE / 2, NULL, 0);

	while (!WindowShouldClose()) {
		float move = GetMouseWheelMove();
		if (move != 0) {
			currFont += move > 0 ? 1 : -1;
			currFont = MAX(0, MIN(N_FONTS-1, currFont));
			printf("font size: %d (%d)\n", fontSizes[currFont], currFont);
		}

		BeginDrawing();
		ClearBackground(GetColor(0));
		/*for (int i = 0; i < 10; i++) {
			DrawTextEx(fonts[i], "amongus", (Vector2){100, (float)i * 100 + 100}, 10 * (float)fontSizes[i] + 10, 0, GetColor(0xffffffff));
		}*/

		DrawTextEx(fonts[currFont], "amongus", (Vector2){0, 0}, (float)fontSizes[currFont], 0, GetColor(0xffffffff));

		EndDrawing();
	}

	CloseWindow();

	printf("Hello, world\n");

	return 0;
}
