class DynamicArray
{
private:
	int top;
	int *array;
	int* resize();
public:
	DynamicArray();
	void append_element(int element);
	int get_element_at_index(int index);
	int size();
	void reset();

	void set_element_at_index(int index, int value);
};