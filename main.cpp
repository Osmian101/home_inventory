#include "main.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>

int main(int argc, char** argv)
{	
	std::vector<Item> inventory;
	std::string file_path = "inventory.csv";
	// load inventory.csv into a vector of Items
	load(file_path, inventory);
	while (1)
	{
		char command;
		std::cin >> command;
		if (command != 'q')
		{
			// TODO: break down command so it can use args 
			std::string test_string = "name4";
			std::cout << command << std::endl;
			switch (command)
			{
				case 'a':
					add(inventory, test_string, 3);
					break;
				case 's':
					subtract(inventory, test_string, 3);
					break;
				case 'd':
					display(inventory);
					break;
				case 'r':	
					remove(inventory, test_string);
					break;
				case 'w':
					save(file_path, inventory);
					break;
				case 'i':
					insert(inventory, test_string, 3);
					break;
				default: 
					print_usage();
					break;
				break;
			}
		}
		else 
		{
			std::cout << "QUIT" << std::endl;
			return -1;
		}
	}
	return 0;
}

void add(std::vector<Item> &inventory, std::string name, int amount)
{
	std::cout << "ADD " << amount << " TO " << name << std::endl;
	// for each item in vector, check if its [name]
	// if so increase by [amount]
	int i = 0;
	for (Item item : inventory)
	{
		if (item.name == name)
		{
			inventory[i].amount += amount;
		}
		i++;
	}

}

void subtract(std::vector<Item> &inventory, std::string name, int amount)
{
	std::cout << "SUBTRACT " << amount << " FROM " << name << std::endl;
	int i = 0;
	for (Item item : inventory)
	{
		if (item.name == name)
		{
			inventory[i].amount -= amount;
		}
		i++;
	}
}

void display(std::vector<Item> &inventory)
{
	std::cout << "DISPLAY" << std::endl;
	for (Item item : inventory)
	{
		std::cout << item.name << std::endl;
		std::cout << item.amount << std::endl;
	}
}

void remove(std::vector<Item> &inventory, std::string name)
{
	std::cout << "REMOVE " << name << std::endl;
	int i = 0;
	for (Item item : inventory)
	{
		if (item.name == name)
		{
			inventory.erase(inventory.begin() + i);
		}
		i++;
	}
}

int insert(std::vector<Item> &inventory, std::string name, int amount)
{
	std::cout << "INSERT " << amount << " " << name << std::endl;
	for (Item item : inventory)
	{
		if (item.name == name)
		{
			std::cerr << name << " ALREADY EXISTS" << std::endl;
			return -1;
		}
	}
	Item new_item;
	new_item.name = name;
	new_item.amount = amount;
	inventory.push_back(new_item);
	return 1;
}

void save(std::string file_path, std::vector<Item> inventory)
{
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
}

void load(std::string file_path, std::vector<Item> &inventory)
{
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
		// read each line into a new Item struct and store it in the inventory vector
		while (i < num_lines)
		{
			Item temp;
			file_in >> temp.name >> temp.amount;
			inventory.push_back(temp);
			i++;
		}
		file_in.close();
	}
}

void print_usage()
{
	std::cerr << "USAGE: inv [a,s,d,r,w,q,h,i] [optional args]" << std::endl;
}
