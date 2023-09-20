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
{	// TODO: break into load_from_file()
	std::vector<Item> inventory;
	std::string file_path = "inventory.csv";
	std::ifstream file_in;
	file_in.open(file_path);
	int num_lines = 0;
	if (file_in.is_open())
	{
		// count number of lines in the file
		for (std::string line; std::getline(file_in, line);)
		{
			num_lines++;
		}
		int i = 0;
		file_in.close();	// close and reopen the file to reset the reader position (TODO: functions for this?)
		file_in.open(file_path);
		while (i < num_lines)
		{
			Item temp;
			file_in >> temp.name >> temp.amount;
			inventory.push_back(temp);
			i++;
		}
	}
	file_in.close();

	// TODO: break out into save_to_file()
	std::ofstream file_out;
	file_out.open(file_path);
	if (file_out.is_open())
	{
		for (Item item : inventory)
		{
			 file_out << item.name << " " << item.amount << std::endl;
		}
		file_out.close();
	}
	
	// TODO: pretty print for struct data
	std::cout << "WHOLE STRUCT" << std::endl;
	for (Item item : inventory)
	{
		std::cout << item.name << std::endl;
		std::cout << item.amount << std::endl;
	}
	return 0;
	// switch on second arg
}
