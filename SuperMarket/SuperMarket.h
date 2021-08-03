#pragma once

#include <iostream>
#include <string>
#include <vector>
#include<stdlib.h>
#include<fstream>

#include"item.h"

int caseInsensiStringCompare(const std::string&, const std::string&);

class SuperMarket {
private:
	std::vector<item> stock;

public:
	//1. adding to the stock
	void addToStock(item* e) {
		stock.emplace_back(*e);
	}

	std::vector<item>::iterator giveMePosi(std::string str) {
		for (std::vector<item>::iterator it = stock.begin(); it != stock.end(); ++it) {
			if (caseInsensiStringCompare(str,it->getName()) == 0)
				return it;
		}

		std::vector<item>::iterator it = stock.end();

		return it;
	}
	int isIteratorValid(std::vector<item>::iterator it) {
		if (it != stock.end()) {
			return 1;
		}
		else
		{
			return 0;
		}
	}
	//Print the stock
	void PrintStock() {
		for (int i = 0; i < stock.size(); i++) {
			std::cout << i+1 << "\t";
			formatting(stock[i].getName());
			std::cout << stock[i].getPrice() << std::endl;
		}

	}

	void read(item* currItem) {
		std::ifstream fin;
		fin.open("stock.txt", std::ios::in | std::ios::binary);
		if (!fin) {
			std::cout << "File not found"<<std::endl;
			return;
		}
		else
		{
			fin.read((char*)currItem, sizeof(*currItem));
			while (!fin.eof()) {
				addToStock(currItem);
				fin.read((char*)currItem, sizeof(*currItem));
				
			}
		}

		fin.close();
	}



};
