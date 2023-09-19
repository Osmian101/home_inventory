#include <iostream>
#include <fstream>
using namespace std;

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
		cout << inventory_file.rdbuf();
	}
	inventory_file.close();
	return 0;
	// open csv
	// switch on second arg
}
