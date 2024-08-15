#include <raylib.h>
#include <stdio.h>

const Vector2 GRAVITY = (Vector2){0, 100};
const float FLAP_TIME_S = 100.0f;
const float BIRD_MASS = 10;

struct BIRD {
	Rectangle rect;
	Vector2 velocity;
	Vector2 acceleration;
	Vector2 sum_force;
};

struct BIRD bird;
void start()
{ 
	bird = (const struct BIRD){
		(Rectangle){10, 0, 10, 10}, // rect
		(Vector2){0, 0}, // velocity
		(Vector2){0, 0}, // acceleration
		(Vector2){0, 0} // sum force
	};

	bird.sum_force.y = BIRD_MASS * GRAVITY.y;
}

void integrate_bird()
{
	bird.acceleration.x = bird.sum_force.x / BIRD_MASS;
	bird.acceleration.y = bird.sum_force.y / BIRD_MASS;

	bird.velocity.x += bird.acceleration.x * GetFrameTime();
	bird.velocity.y += bird.acceleration.y * GetFrameTime();

	bird.rect.x += bird.velocity.x * GetFrameTime();
	bird.rect.y += bird.velocity.y * GetFrameTime();
}

float flap_time = 0;
void flap()
{
	bool rising = false, first_risen = false;

	if (IsKeyPressed(KEY_SPACE))
	{
		rising = true;
	}

	if (rising)
	{
		flap_time += GetFrameTime();

		if (first_risen)
		{
			bird.sum_force.y -= 10000;
			first_risen = false;
		}

		rising = flap_time >= FLAP_TIME_S;
	}
}

void update()
{
	integrate_bird();
	flap();
}

void draw()
{
	DrawRectangleRec(bird.rect, RAYWHITE);
}
