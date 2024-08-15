#include <stdio.h>
#include <vector>
using std::vector;
#include <raylib.h>

char board[40][40];
char next_board[40][40];

void initialize_board()
{
	for (int i = 0; i < 40; i++)
	{
		for (int j = 0; j < 40; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void start()
{
	initialize_board();
}

vector<Vector2> snake;
void take_input()
{
	if (IsKeyPressed(KEY_D))
	{
		snake[0] = {1, 0};
	}
	if (IsKeyPressed(KEY_A))
	{
		snake[0] = {-1, 0};
	}
	if (IsKeyPressed(KEY_W))
	{
		snake[0] = {0, -1};
	}
	if (IsKeyPressed(KEY_S))
	{
		snake[0] = {0, 1};
	}
}
void update()
{
	take_input();
}

void draw_board()
{
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++)
		{
			if (board[y][x] != ' ')
			{
				switch (board[y][x])
				{
					case '#':
						DrawRectangleV((Vector2){x*10.0f, y*10.0f}, (Vector2){10,10}, RAYWHITE);
				}
			}
		}
	}
}

void draw()
{
	draw_board();
}
