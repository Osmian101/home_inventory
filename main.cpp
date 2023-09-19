#include <iostream>
#include <fstream>
using namespace std;

struct Item
{
	string name;
	int amount;
};

// setup argv
int main()
{
	string file_path = "inventory.csv";
	ifstream inventory_file;
	inventory_file.open(file_path);
	if (inventory_file.is_open())
	{
		// read data char by char, split data on comma, new entry by line
		// replace cout with item struct
		for (string line; getline(inventory_file, line, ',');)
		{
			cout << line << endl;
		}
	}
	inventory_file.close();
	return 0;
	// switch on second arg
}
