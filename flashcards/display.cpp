#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "./globals.cpp"
using std::string, std::vector;

const int LINE_LENGTH = 40;

const int FONT_SIZE = 30;

void load_iosevka()
{
	iosevka = LoadFontEx("/run/media/abrar/dev/misc-ray-projs/flashcards/iosevka.ttf", FONT_SIZE, NULL, 0);
}

vector<string> wrap_text_lengthwise(string text)
{
	vector<string> res;
	string line = "";

	int last_space_index = -1;
	for (int i = 0; i < text.length(); i++)
	{
		line += text[i];
		if (text[i] == ' ')
			last_space_index = i;
		if ((i + 1) % LINE_LENGTH == 0)
		{
			res.push_back(line);
			line = "";
		}
	}
	res.push_back(line);

	return res;
}

void print_wrapped_text(vector<string>* text)
{
	int text_y = 0;
	for (string i : *text)
	{
		Vector2 line_dims = MeasureTextEx(iosevka, i.c_str(), FONT_SIZE, 0);
		float padding = 20;
		Rectangle background_rect = (Rectangle){(float)800/2 - (line_dims.x + padding)/2, ((float)450/2 - (float)(text->size() * FONT_SIZE)/2), line_dims.x + padding, (text->size() * FONT_SIZE) + padding};

		DrawTextEx(iosevka, i.c_str(), (Vector2){(float)800/2 - line_dims.x/2, ((float)450/2 - (float)(text->size() * FONT_SIZE)/2) + (float)text_y}, FONT_SIZE, 0, FG);
		text_y += FONT_SIZE;
	}
}

int q_count = 0, a_count = 0;
bool is_q_displayed = true;
void display_qna(vector<string>* q, vector<string>* a)
{
	int number_of_pairs = (int)q->size();
	string current_display = "";

	if (q_count < q->size() or a_count < a->size())
	{
		if (is_q_displayed)
			current_display = q->at(q_count);
		else
			current_display = a->at(a_count);
	}
	else 
	{
		current_display = "(R) to replay and (ESC) to quit.";
		if (IsKeyPressed(KEY_R))
		{
			q_count = 0;
			a_count = 0;
		}
	}

	if (IsKeyPressed(KEY_A))
	{
		if (is_q_displayed) 
		{
			q_count++;
		}
		else 
		{
			a_count++;
		}

		is_q_displayed = !is_q_displayed;
	}

	vector<string> strings_to_display = wrap_text_lengthwise(current_display);
	print_wrapped_text(&strings_to_display);
}
