#include <raylib.h>

Rectangle rect;

float mass = 10, sum_force, acc, vel;

void start()
{
	rect.x = 190;
	rect.y = 380;
	rect.width = 10;
	rect.height = 10;
}

void integrate()
{
	acc = sum_force / mass;
	vel += acc * GetFrameTime();
	rect.y += vel * GetFrameTime();
}

float timer = 0;
void add_impulse(float mag, float time)
{
	timer += GetFrameTime();
}

void update()
{
	integrate();
}

void draw()
{
	DrawRectangleRec(rect, RAYWHITE);
}
