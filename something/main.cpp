#include "./component.cpp"
#include <raylib.h>
#include <vector>
#include <iostream>
using std::vector;

int main(void)
{
	vector<Component> Components;
	Components.push_back(Component());

	const int WINDOW_WIDTH = 800;
	const int WINDOW_HEIGHT = 450;
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "TITLE");

	while (!WindowShouldClose())
	{
		for (auto i : Components)
			i.Update();

		BeginDrawing();
			ClearBackground(RAYWHITE);
			for (auto i : Components)
				i.Draw();

		EndDrawing();
	}

	CloseWindow();
}
