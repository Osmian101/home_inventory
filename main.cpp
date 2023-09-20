#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Item
{
	std::string name;
	int amount;	
};

// setup argv
int main()
{
	std::vector<Item> inventory;
	std::string file_path = "inventory.csv";
	std::ifstream file_in;
	file_in.open(file_path);
	int num_lines = 0;
	if (file_in.is_open())
	{
		// TODO: this for every line in the file (currently once)
		for (std::string line; std::getline(file_in, line);)
		{
			num_lines++;
		}
		int i = 0;
		file_in.close();	// close and reopen the file to reset the reader position (TODO: functions for this?)
		file_in.open(file_path);
		while (i <= num_lines)
		{
			Item temp;
			file_in >> temp.name >> temp.amount;
			inventory.push_back(temp);
			i++;
		}
	}
	file_in.close();
	
	// TODO: pretty print for struct data
	std::cout << "WHOLE STRUCT" << std::endl;
	for (int i = 0; i < 3; i++)
	{
		std::cout << inventory[i].name << std::endl;
		std::cout << inventory[i].amount << std::endl;
	}
	return 0;
	// switch on second arg
}
