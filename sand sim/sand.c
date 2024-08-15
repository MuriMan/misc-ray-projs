#include <raylib.h>

int grid[40][40];
int new_grid[40][40];

void draw_grid()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (grid[y][x] == 1)
				DrawRectangleV((Vector2){x * 10, y * 10}, (Vector2){10, 10}, RAYWHITE);
		}
	}
}

void step_grid()
{
	for (int y = 0; y < 39; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (grid[y][x] == 1 && grid[y+1][x] != 1)
			{
				new_grid[y][x] = 0;
				new_grid[y+1][x] = 1;
			}
		}
	}

	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			grid[y][x] = new_grid[y][x];
		}
	}
}

void mouse()
{
	if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
	{
		grid[GetMouseY()/10][GetMouseX()/10] = 1;
	}

}

void draw_mouse()
{
	DrawRectangle(GetMouseX() - (GetMouseX() % 10), GetMouseY() - (GetMouseY() % 10), 10, 10, 
	RAYWHITE);
}

void start()
{
	DisableCursor();
}

float dt_timer = 0;
void update()
{
	dt_timer += GetFrameTime();

	if ((dt_timer - (float)1/30) > 0)
	{
		step_grid();
		dt_timer = 0;
	}

	mouse();
}

void draw()
{
	draw_grid();
	draw_mouse();
}

