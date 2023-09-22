#ifndef MAIN_H
#define MAIN_H
#include <vector>
#include <iostream>

struct Item
{
	std::string name;
	int amount;
};

int main(int argc, char** argv);

void add(std::string name, int amount);

void subtract(std::string name, int amount);

void display(std::vector<Item> inventory);

void remove(std::string name);

void save(std::string file_path, std::vector<Item> inventory);

void print_usage();

#endif
