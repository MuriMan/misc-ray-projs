#include <raylib.h>
#include "ship.c"
#include "bullet.c"

SHIP ship;
BULLET* bullets;

const float BULLET_SPEED = 20;

void start()
{
	ship = (SHIP)
	{(Vector2){(float)640/2, (float)480/2}, (Vector2){0, 0}, (float)PI/2, 0};
}

int speed_increase_direction = 1;
int rotation_increase_direction = 1;
void take_input()
{
	if (IsKeyDown(KEY_W)) 
	{
		speed_increase_direction = 1;
		accelerate_ship(&ship, (float)1/2 * speed_increase_direction);
	}
	else if (IsKeyDown(KEY_S)) 
	{
		speed_increase_direction = -1;
		accelerate_ship(&ship, (float)1/2 * speed_increase_direction);
	}

	if (IsKeyDown(KEY_A)) 
	{
		rotation_increase_direction = -1;
		rotate_ship(&ship, (PI/5000) * rotation_increase_direction);
	}
	else if (IsKeyDown(KEY_D)) 
	{
		rotation_increase_direction = 1;
		rotate_ship(&ship, (PI/5000) * rotation_increase_direction);
	}

	if (IsKeyPressed(KEY_SPACE))
	{
		Vector2 player_velocity_normal = normalise_vector(ship.velocity);
			
		instance_bullet(bullets, (BULLET){ship.pointer, 
			(Vector2){player_velocity_normal.x * BULLET_SPEED,
				player_velocity_normal.y * BULLET_SPEED
			}
		});
	}
}
void update()
{
	if (ship.rotation_rad >= ((float)5/2*PI))
		ship.rotation_rad -= (float)5/2*PI;

	take_input();

	calculate_pointer(&ship);
	calculate_velocity(&ship);
	wrap_ship(&ship);
	integrate_ship(&ship);
}

void draw()
{
	draw_ship(&ship);

	for (int i = 0; i < sizeof(bullets)/sizeof(BULLET); i++)
	{
		draw_bullet(&bullets[i]);
	}
}

void end()
{

}
