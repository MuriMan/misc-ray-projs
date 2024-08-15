#include <raylib.h>
#include "./snake.cpp"

int main(void)
{
	InitWindow(400, 400, "SNAKE");
	start();

	while (!WindowShouldClose())
	{
		update();
		BeginDrawing();
			draw();
			ClearBackground(BLACK);
		EndDrawing();
	}

	CloseWindow();
}
