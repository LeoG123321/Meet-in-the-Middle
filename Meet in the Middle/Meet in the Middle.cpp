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

double mean(DynamicArray);
DynamicArray mode(DynamicArray numArray);

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
	
	data = "104,11,90,8,6,90,2,71,45,27,9,2,1";
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

	cout << endl;
	cout << "Unsorted Data: " << endl;
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray.get_element_at_index(i) << endl;
	}

	int temp;

	for (int i = 0; i < numArray.size(); i++) {
		for (int j = 0; j < numArray.size() - 1; j++) {
			if (numArray.get_element_at_index(j) > numArray.get_element_at_index(j + 1)) {
				temp = numArray.get_element_at_index(j);
				numArray.set_element_at_index(j, numArray.get_element_at_index(j + 1));
				numArray.set_element_at_index(j + 1, temp);
			}
		}
	}

	cout << endl;
	cout << "Sorted Data: " << endl;
	for (int i = 0; i < numArray.size(); i++) {
		cout << numArray.get_element_at_index(i) << endl;
	}

	cout << endl;
	cout << "Median: " << median(numArray) << endl;
	cout << "Mean: " << mean(numArray) << endl;

	DynamicArray modes = mode(numArray);

	cout << "Modes: " << endl;
	for (int i = 0; i < modes.size(); i++) {
		cout << modes.get_element_at_index(i) << endl;
	}
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

double mean(DynamicArray numArray) {
	double total = 0;
	for (int i = 0; i < numArray.size(); i++) {
		total += numArray.get_element_at_index(i);
	}
	return total / numArray.size();
}

DynamicArray mode(DynamicArray numArray) {
	DynamicArray num_list;
	DynamicArray num_counters;
	bool duplicate_num_flag = false;
	int index;
	for (int i = 0; i < numArray.size(); i++) {
		for (int j = 0; j < num_list.size(); j++) {
			if (numArray.get_element_at_index(i) == num_list.get_element_at_index(j)) {
				duplicate_num_flag = true;
				num_counters.set_element_at_index(j, num_counters.get_element_at_index(j) + 1);
			}
		}
		if (!duplicate_num_flag) {
			num_list.append_element(numArray.get_element_at_index(i));
			num_counters.append_element(1);
		}
		duplicate_num_flag = false;
	}

	int largest_num = 0;

	for (int i = 0; i < num_counters.size(); i++) {
		if (num_counters.get_element_at_index(i) > largest_num) {
			largest_num = num_counters.get_element_at_index(i);
		}
	}

	DynamicArray modes;
	for (int i = 0; i < num_counters.size(); i++) {
		if (num_counters.get_element_at_index(i) == largest_num) {
			modes.append_element(num_list.get_element_at_index(i));
		}
	}

	return modes;
}