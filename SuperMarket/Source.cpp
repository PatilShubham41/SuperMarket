#include <iostream>
#include <string>
#include <vector>
#include<stdlib.h>
#include<algorithm>
#include"SuperMarket.h"
#include"item.h"

int caseInsensiStringCompare(const std::string& str1, const std::string& str2) {
	std::string str1cpy(str1);
	std::string str2cpy(str2);
	std::transform(str1cpy.begin(), str1cpy.end(), str1cpy.begin(), ::tolower);
	std::transform(str2cpy.begin(), str2cpy.end(), str2cpy.begin(), ::tolower);

	if (str1cpy == str2cpy)
		return 0;
	else
	{
		return 1;
	}
}

class Cart {
private:
	int numItem=0;
	float cartTotal=0;
	//create vector of item
	std::vector <item> myCart;
	

public:
	//should have add to cart
	void addToCart(std::string e, SuperMarket& mart,int &numOfItem) {//add the item to cart
		std::vector<item>::iterator a = mart.giveMePosi(e);
		if (mart.isIteratorValid(a)) {
			a->addItemNum(numOfItem);
			myCart.emplace_back(*a);
			numItem = myCart.size();
		}
		else
		{
			std::cout << "Enter the correct name";
		}
	}

	void removeFromCart(std::string drop) {//Remove the item from cart
		 
		std::vector<item>::iterator temp = myCart.end();

		for (std::vector<item>::iterator it = myCart.begin(); it != myCart.end(); ++it) {
			if (caseInsensiStringCompare(drop, it->getName()) == 0) {
				temp = it;
			}

		}

		if(temp!= myCart.end())
			myCart.erase(temp);
		else {
			std::cout << "Enter the correct name";
			std::getchar();
		}

	}

	void printTotal(float total) { //Print the Cart Total
		std::cout << std::endl << "" << "\t";
		formatting("Total");
		std::cout<< "\t" << total<<std::endl;
		cartTotal = 0;

	}

	void total() { //Evalute the Cart total
		for (int i = 0; i < myCart.size(); i++) {
			cartTotal = myCart[i].numItemInCart() * myCart[i].getPrice() + cartTotal;
			
		}
		printTotal(cartTotal);
	}

	bool isCartEmpty() {
		if (cartTotal > 0)
			return false;
		else
			return true;
	}


	void printCart() { //Printing the all cart values
		for (int i = 0; i < myCart.size(); i++) {
			std::cout << i << "\t"; 
			formatting(myCart[i].getName());
			std::cout << "\t" << myCart[i].getPrice() << "\tx" << myCart[i].numItemInCart() << std::endl;
		}
		total();
	}
	void incrementOrDecreaseCount(std::string e, int& numOfItem) {
		for (std::vector<item>::iterator it = myCart.begin(); it != myCart.end(); ++it) {
			if (caseInsensiStringCompare(e, it->getName()) == 0) {
				it->addItemNum(numOfItem);

			}

		}
		
		

	}
};
void PrintConsole(SuperMarket& s_name, Cart& c_name) { //Print the farmated cart and stock
	system("CLS");
	s_name.PrintStock();
	std::cout << std::endl << std::endl << "================= YOUR CART IS DISPLAYING BELOW ==================" << std::endl << std::endl;
	c_name.printCart();

}

int main()
{
	/*
	item one(123.42f, "Sugar");//crated 1
	item second(40.56f, "Rice"),third(100.0f, "edible oil"),fourth(40.0f,"Colgate");//crated 2,3,4
	item fifth(3.0f, "Shampoo"), sixth(150.05f, "DEO"), seventh(12.00f, "Maggi"), eighth(10.0f, "Washing Soap"), nineth(30.40f, "Bathing Soap"), Tenth(250.0f, "Cashew"), eleventh(200.0f, "Almond");

	
	one.write();
	second.write();
	third.write();
	fourth.write();
	fifth.write();
	sixth.write();
	seventh.write();
	eighth.write();
	nineth.write();
	Tenth.write();
	eleventh.write();*/

	
	item five;
	item* ptrItem = &five;
	Cart k;
	
	//Need to object creation 1.Read from file 2.Add to stock
	SuperMarket Mart;
	
	Mart.read(ptrItem);

	Cart myCart;
	int counter = 1;
	std::string input;
	//loop creation for cart creation
	while (true)
	{	
		//1.display stock
		if (counter == 1) {// first execution
			Mart.PrintStock();
			std::cout << "Specify any following action" << std::endl;
			std::cout << "1. Add To Cart\n2. Remove from Cart\n3. Check Out" << std::endl;
		}
		else
		{
			//3.display cart 
			PrintConsole(Mart, myCart);
			std::cout << "Specify any following action" << std::endl;
			std::cout << "1. Add To Cart\n2. Remove from Cart\n3. Check Out\n4.Update the item count" << std::endl;


		}
		int num = 0;
		
		//std::cin.ignore();
		std::cin >> input;
		
		std::transform(input.begin(), input.end(), input.begin(), ::tolower);//makes loweCase
		//2.give option like a)add b) remove c)check out
		if (input.compare("add")==0) {
			std::cout << "Enter item name" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, input);
		
			std::cout << "Enter the number of above item you want to add " << std::endl;
			std::cin >> num;
			myCart.addToCart(input, Mart,num); //Need to re-write the function based on string
			counter++;
		}

		else if (input.compare("remove")==0) {
			std::cout << "Enter item name" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, input);
			myCart.removeFromCart(input);
			counter++;
		}
		else if (input.compare("update")==0) {
			std::cout << "Enter item name" << std::endl;
			std::cin.ignore();
			std::getline(std::cin, input);
			std::cout << "Enter the update item count " << std::endl;
			std::cin >> num;
			myCart.incrementOrDecreaseCount(input,num);
			counter++;
		}

		else if (input.compare("out") == 0) {
			system("CLS");
			if (!myCart.isCartEmpty()) {
				std::cout << "Your Grand Total is: " << std::endl;
				myCart.total();
			
			}
			return -1;

		}
			

		else{
			system("CLS");
			std::cout << "Please enter valid input" << std::endl;
			std::cin.ignore();
			std::getchar();
		}
			
		
		
		
		//2.give option like a)add b) remove c)check out
		
	}
	
}