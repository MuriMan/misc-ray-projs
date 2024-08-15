#include <raylib.h>
#include <math.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 450;
const int BLOB_RADIUS = 10;

// a comment

float DistanceBetween(Vector2* a, Vector2* b)
{
	return sqrt(pow((b->x - a->x),2) + pow((b->y - a->y),2));
}

Vector2 RedoBlobPosition()
{
	return (Vector2){GetRandomValue(BLOB_RADIUS, WINDOW_WIDTH - BLOB_RADIUS), GetRandomValue(BLOB_RADIUS, WINDOW_HEIGHT - BLOB_RADIUS)};
}

int main(void)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Guy");

	Vector2 BlobPosition = {GetRandomValue(0, WINDOW_WIDTH), GetRandomValue(0, WINDOW_HEIGHT)};
	while (!WindowShouldClose())
	{
		Vector2 MousePos = GetMousePosition();
		if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && DistanceBetween(&MousePos,
			&BlobPosition) < BLOB_RADIUS)
			BlobPosition = RedoBlobPosition();

		BeginDrawing();
			ClearBackground(BLACK);

			DrawCircleV(BlobPosition, BLOB_RADIUS, WHITE);
		EndDrawing();
	}
	CloseWindow();
}
