#include <raylib.h>
#include <iostream>
#include <vector>
using std::vector, std::string;

#include "./file_parsing.cpp"
#include "./display.cpp"

vector<string> questions;
vector<string> answers;

void start()
{
	parse_file(&questions, &answers, "./base.txt");
	load_iosevka();
}

void update()
{
	
}

void draw()
{
	display_qna(&questions, &answers);
}
