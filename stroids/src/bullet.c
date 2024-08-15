#include <raylib.h>
#include <stdlib.h>

const int BULLET_RADIUS = 5;

typedef struct BULLET {
	Vector2 position, velocity;
} BULLET;

void integrate_bullet(BULLET* bullet)
{
	bullet->position.x += bullet->velocity.x * GetFrameTime();
	bullet->position.y += bullet->velocity.y * GetFrameTime();
}

void instance_bullet(BULLET* bullets, BULLET new_bullet)
{
	BULLET* n = malloc(sizeof(bullets) + sizeof(BULLET));
	if (n == NULL)
		exit(1);
	for (int i = 0; i < sizeof(bullets)/sizeof(BULLET); i++)
	{
		n[i] = bullets[i];
	}
	n[sizeof(n) - 1] = new_bullet;

	free(n);
}

void draw_bullet(BULLET* bullet)
{
	DrawCircleV(bullet->position, BULLET_RADIUS, GREEN);
}
