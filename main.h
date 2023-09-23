#ifndef MAIN_H
#define MAIN_H
#include <vector>
#include <iostream>

struct Item
{
	std::string name;
	// department enum (produce, dairy, seafood, etc.)
	int amount;
};

int main(int argc, char** argv);

void add(std::vector<Item> &inventory, std::string name, int amount);

void subtract(std::vector<Item> &inventory, std::string name, int amount);

void display(std::vector<Item> &inventory);

void remove(std::vector<Item> &inventory, std::string name);

void save(std::string file_path, std::vector<Item> inventory);

int insert(std::vector<Item> &inventory, std::string name, int amount);

void print_usage();

#endif
