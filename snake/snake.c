#include <raylib.h>
#include "./consts.c"

Vector2 snake_directions[100 * 100];
Vector2 snake_positions[100 * 100];
int snake_length = 1;
 
void start_snake()
{
	for (int i = 0; i < (100 * 100); i++)
	{
		snake_directions[i] = (Vector2){0, 0};
		snake_positions[i] = (Vector2){0, 0};
	}
}

void update_snake()
{
	if (IsKeyDown(KEY_W))
		snake_directions[snake_length-1].y = -1;
	else if (IsKeyDown(KEY_S))
		snake_directions[snake_length-1].y = 1;
	else if (IsKeyDown(KEY_A))
		snake_directions[snake_length-1].x = -1;
	else if (IsKeyDown(KEY_W))
		snake_directions[snake_length-1].x = 1;

	for (int i = 0; i < snake_length; i++)
	{
		snake_positions[i].x += snake_directions[i].x * UNIT;
		snake_positions[i].y += snake_directions[i].y * UNIT;
	}
	
}

void draw_snake()
{
	for (int i = 0; i < snake_length; i++)
	{
		DrawRectangleV(snake_positions[i], (Vector2){UNIT, UNIT}, WHITE);
	}
}
