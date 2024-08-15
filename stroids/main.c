#include <stdio.h>
#include <raylib.h>
#include "./src/game.c"

int main(void)
{
	InitWindow(640, 480, "STROIDS");
	start();

	while (!WindowShouldClose())
	{
		update();

		BeginDrawing();
			ClearBackground(BLACK);
			draw();
		EndDrawing();
	}

	end();
	CloseWindow();
}
