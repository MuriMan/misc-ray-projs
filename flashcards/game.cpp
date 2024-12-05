#include <raylib.h>
#include <iostream>
#include <vector>
using std::vector, std::string;

#include "./file_parsing.cpp"

vector<string> questions;
vector<string> answers;

void start()
{
	parse_file(&questions, &answers, "./base.txt");
}

void update()
{
}

void draw()
{
	DrawText("HI", 0, 0, 100, WHITE);
}
