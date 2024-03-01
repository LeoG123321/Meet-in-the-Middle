#include <iostream>
#include "DynamicArray.h"

int* DynamicArray::resize() {
	int* tempArray = new int[top+1+1];
	for (int i = 0; i < size(); i++) {
		tempArray[i] = array[i];
	}
	delete[] array;
	top++;
	return tempArray;
}

DynamicArray::DynamicArray() {
	top = -1;
}
void DynamicArray::append_element(int element) {
	array = resize();
	array[top] = element;
}
int DynamicArray::get_element_at_index(int index) {
	return array[index];
}
int DynamicArray::size() {
	return top + 1;
}
void DynamicArray::reset() {
	top = -1;
}
