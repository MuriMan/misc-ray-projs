#include <raylib.h>
#include "./snake.c"

void start()
{
	start_snake();
}

float time = 0;
void update()
{
	update_snake();

	time += GetFrameTime();
}

void draw()
{
	draw_snake();
}
