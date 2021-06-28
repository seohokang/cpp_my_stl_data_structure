#include "int_array.h "

int main()
{
	// Constructors
	// Destructors
	// initialize() : Used this function in constructor
	// reset() : delete memory and go to initial
	// resize() : change size
	// insert_before(const int & value, const int & idx)
	// remove(const int & idx);
	// push_back(const int& value);
	IntArray default_array;
	default_array = { 1,2,3 };
	cout << "Default Contructor Test: " << default_array << endl;
	IntArray int_array{ 1,3,5,7,9 };
	cout << "Constructor Test: " << int_array << endl;
	int_array.insert_before(10,1); // 1,10,3,5,7,9   
	cout << "Intsert Before Test: " << int_array << endl;
	int_array.remove(3);		   // 1,10,3,7,9
	cout << "Remove Test: " << int_array << endl;
	int_array.push_back(13);       // 1,10,3,7,9,13
	cout << "Push Back Test: " << int_array << endl;
	int_array.resize(4);		   // 1,10,3,7
	cout << "Resize Test: " << int_array << endl;
	IntArray int_array2;
	int_array2 = int_array;
	cout << "Assignment Operator Overloading Test: " << int_array2 << endl;
	int e = int_array[3];
	cout << "Indexing Test: " << e << endl;
	int_array.reset();
	cout << "Reset Test: " << int_array << endl;
	return 0;
}