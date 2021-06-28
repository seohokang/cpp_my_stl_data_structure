#pragma once
#include <iostream>
using namespace std;
class IntArray
{
public:
	IntArray();
	IntArray(int length);
	IntArray(const initializer_list<int>& list);
	~IntArray();

	void initialize();
	void reset();
	void resize(const int& length);
	void insert_before(const int& value, const int& idx);
	void remove(const int& idx);
	void push_back(const int& value);
	friend ostream& operator << (ostream& out, IntArray& arr);
	int& operator [](int i);
	IntArray& operator =(const IntArray& int_array);
private:
	int* m_data = nullptr; // initialize array address which is going to be dynamically allocated
	int m_length = 0;
};