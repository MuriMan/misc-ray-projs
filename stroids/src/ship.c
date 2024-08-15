#include <raylib.h>
#include <math.h>

const int SHIP_RADIUS = 15;

typedef struct SHIP {
	Vector2 position, velocity, pointer;
	float rotation_rad, speed;
} SHIP;

void accelerate_ship(SHIP* ship, float magnitude)
{
	ship->speed += magnitude;
}

void calculate_velocity(SHIP* ship)
{
	ship->velocity.x = ship->speed * cos(ship->rotation_rad);
	ship->velocity.y = ship->speed * sin(ship->rotation_rad);
}

void integrate_ship(SHIP* ship)
{
	ship->position = (Vector2){
		ship->position.x + (ship->velocity.x * GetFrameTime()), 
		ship->position.y + (ship->velocity.y * GetFrameTime())
	};
}

void rotate_ship(SHIP* ship, float magnitude)
{
	ship->rotation_rad += magnitude;
}

void calculate_pointer(SHIP* ship)
{
	ship->pointer = (Vector2){
		ship->position.x + SHIP_RADIUS * cos(ship->rotation_rad),
		ship->position.y + SHIP_RADIUS * sin(ship->rotation_rad)
	};
}

void wrap_ship(SHIP* ship)
{
	if (ship->position.x > 640)
		ship->position.x = 0;
	else if (ship->position.x < 0)
		ship->position.x = 640;

	if (ship->position.y > 480)
		ship->position.y = 0;
	else if (ship->position.y < 0)
		ship->position.y = 480;
}

float magnitude_vector(Vector2 vec)
{
	return sqrt(vec.x * vec.x + vec.y * vec.y);
}

Vector2 normalise_vector(Vector2 vec)
{
	Vector2 res;
	float mag_vec = magnitude_vector(vec);

	res.x = vec.x / mag_vec;
	res.y = vec.y / mag_vec;

	return res;
}

void draw_ship(SHIP* ship)
{
	DrawCircleV(ship->position, SHIP_RADIUS, RAYWHITE);
	DrawCircleV(ship->pointer, 4, RED);
}
