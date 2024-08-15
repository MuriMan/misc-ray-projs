#include <raylib.h>

Vector2 pos = (Vector2){0, 0};

int main(void)
{
	InitWindow(400, 400, "HI");

	while (!WindowShouldClose())
	{
		if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
		{
			pos = GetMousePosition();
		}
		if (pos.y != 0)
			pos.y += 1;

		BeginDrawing();
			ClearBackground(BLACK);
			DrawRectangleV(pos, (Vector2){10, 10}, RAYWHITE);
		EndDrawing();
	}
}
