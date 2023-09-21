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

void add(char* name, int amount);

void subtract(char* name, int amount);

void display(std::vector<Item> inventory);

void remove(char* name);

void save(std::string file_path, std::vector<Item> inventory);

void print_usage();

#endif
