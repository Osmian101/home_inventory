#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Item
{
	std::string name;
	int amount;	// TODO: get int working
};

// setup argv
int main()
{
	std::vector<Item> inventory;
	std::string file_path = "inventory.csv";
	std::ifstream file_in;
	file_in.open(file_path);
	if (file_in.is_open())
	{
		// TODO: this for every line in the file (currently wrong)
		for (std::string line; getline(file_in, line, ',');)
		{
			Item temp;
			file_in >> temp.name >> temp.amount;
			inventory.push_back(temp);	
		}
	}
	file_in.close();
	
	// TODO: pretty print for struct data
	std::cout << inventory[0].name << std::endl;
	std::cout << inventory[0].amount << std::endl;

	return 0;
	// switch on second arg
}
