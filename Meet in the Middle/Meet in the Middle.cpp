/*
    Leonardo Gonzalez   2/22/2024
    
    Week 6              Meet in the Middle
*/

#include <iostream>
#include <fstream>
#include "DynamicArray.h"
using namespace std;

int digitMultiplier(int);
int createNumber(DynamicArray);
int median(DynamicArray);

int main()
{
	string data;
	ifstream file; //ifstream lets us read data from a file

	//Include this group of code you are using a text file to grab the numbers
	/*
	file.open("C:\\Users\\Leo\\Desktop\\data.txt", ios::in); //Opens file "data.txt" using the File path to data.txt
	file >> data;	//Sends the line of text to string data
	cout << data << endl;
	file.close();	//Closes File
	*/

	//Include this if you are not using a text file
	
	data = "1,2,6,8,9,11,27,45,71,90,104";
	cout << data << endl;

	DynamicArray numArray;
	DynamicArray num;

	for (int i = 0; i < data.size(); i++) {
		if (data[i] != ',') {
			num.append_element(data[i] - 48);
		}
		else {
			numArray.append_element(createNumber(num));

			num.reset();
		}
	}
	numArray.append_element(createNumber(num));

	cout << "Median: " << median(numArray);
	
}

int digitMultiplier(int exponent) {
	if (exponent == 1) {
		return 1;
	}
	return 10 * digitMultiplier(exponent - 1);
}

int createNumber(DynamicArray num) {
	int number = 0;
	
	for (int i = 0; i < num.size(); i++) {
		number += num.get_element_at_index(num.size() - 1 - i) * digitMultiplier(i + 1);
	}
	return number;
}

int median(DynamicArray numArray) {
	if (numArray.size() % 2 == 1) {
		return numArray.get_element_at_index(numArray.size() / 2);
	}
	else {
		return (numArray.get_element_at_index(numArray.size() / 2) + numArray.get_element_at_index(numArray.size() / 2 - 1)) / 2;
	}
}