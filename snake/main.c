#include <raylib.h>
#include "./game.c"

int main(void)
{
	SetTargetFPS(50);
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "snek");
	start();

	while (!WindowShouldClose())
	{
		update();

		BeginDrawing();
			ClearBackground(BLACK);
			draw();
		EndDrawing();
	}

	CloseWindow();
}
