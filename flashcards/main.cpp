#include <raylib.h>
#include "./game.cpp"

int main(void)
{
	InitWindow(400, 400, "HI");
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
