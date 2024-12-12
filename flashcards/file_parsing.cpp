#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using std::vector, std::string;

void parse_file(vector<string>* q, vector<string>* a, string filepath)
{
	bool is_q = false;

	std::fstream file;
	file.open(filepath);

	string line;
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (line == "---") 
			{
				is_q = !is_q;
			}
			else if (is_q)
			{
				q->push_back(line);
				std::cout << line << std::endl;
			}
			else
			{
				a->push_back(line);
				std::cout << line << std::endl;
			}
		}
	}

	file.close();
}
