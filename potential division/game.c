#include <raylib.h>
#include <math.h>
const int SLIDER_RADIUS = 10;

float distance_of(Vector2 a, Vector2 b)
{
	return (float)sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool is_on_top(Vector2 position, int radius)
{
	return distance_of((Vector2){GetMouseX(), GetMouseY()}, position) < radius;
}

float voltage = 2.0;

void start()
{
}

void update()
{
}

void draw()
{
	DrawCircleV(( Vector2 ){ 200, 200 }, SLIDER_RADIUS, WHITE);
}
