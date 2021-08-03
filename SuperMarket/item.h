#pragma once

#include <iostream>
#include <string>
#include <vector>
#include<stdlib.h>


int colWidth = 50;

void formatting(std::string column) {
	int numOfSpace = colWidth - column.length();
	std::cout << column;
	for (int i = 0; i < numOfSpace; i++) {
		std::cout << " ";
	}

}

class item {

private:
	float price;
	std::string name;
	int numOfItemInCart = 0;


public:
	item(float x, std::string y) {
		price = x;
		name = y;
	}
	item()
	{

	}

	~item() {

	}

	float getPrice() {
		return price;
	}

	std::string getName() {
		return name;
	}
	void addItemNum(int x) {
		this->numOfItemInCart = x;
	}
	int numItemInCart(){
		return numOfItemInCart;
	}

	void write() {
		std::ofstream fout;
		fout.open("stock.txt", std::ios::app | std::ios::binary);
		fout.write((char*)this, sizeof(*this));
		fout.close();
	}
};