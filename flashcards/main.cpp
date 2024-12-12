#include <raylib.h>
#include "./game.cpp"

int main(void)
{
	InitWindow(800, 450, "HI");
	start();

	while (!WindowShouldClose())
	{
		update();

		BeginDrawing();
			ClearBackground(BBG);
			draw();
		EndDrawing();
	}

	CloseWindow();
}
