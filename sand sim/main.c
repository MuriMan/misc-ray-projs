#include <raylib.h>
#include "./sand.c"

int main(void)
{
	InitWindow(400, 400, "SAND");
	/* SetTargetFPS(30); */

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
