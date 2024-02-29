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

int main()
{
	string data;
	ifstream file; //ifstream lets us read data from a file

	file.open("C:\\Users\\Leo\\Desktop\\data.txt", ios::in); //Opens file "data.txt" using the File path to data.txt

	file >> data;	//Sends the line of text to string data

	cout << data << endl;
		
	file.close();	//Closes File
	
	DynamicArray numArray;
	DynamicArray num;

	for (int i = 0; i < data.size(); i++) {
		if (data[i] != ',') {
			num.append_element(data[i] - 48);
			cout << "num get element = " << num.get_element_at_index(num.size() - 1) << endl;
		}
		else {
			numArray.append_element(createNumber(num));
			cout << "numArray get element = " << numArray.get_element_at_index(num.size() - 1) << endl;

			num.reset();
			cout << "num reset" << endl;
		}
	}

	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray.get_element_at_index(i) << endl;
	}
	
}

int digitMultiplier(int exponent) {
	if (exponent == 0) {
		return 1;
	}
	return 10 * digitMultiplier(exponent--);
}

int createNumber(DynamicArray num) {
	int number = 0;
	for (int i = 0; i < num.size(); i++) {
		number += num.get_element_at_index(i) * digitMultiplier(i);
	}
	cout << "number created = " << number << endl;
	return number;
}