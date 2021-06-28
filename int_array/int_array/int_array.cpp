#include "int_array.h"

IntArray::IntArray()
{}

IntArray::IntArray(int length)
	:m_length{length}
{
	initialize(); //Get int*length sized memory from OS, allocate to heap
}

IntArray::IntArray(const initializer_list<int>& list)
	: IntArray(list.size())
{
	int count = 0;
	for (auto& e : list)
	{
		m_data[count] = e;
		++count;
	}
}

IntArray::~IntArray()
{
	delete[] this->m_data;
}

void IntArray::initialize()
{
	m_data = new int[m_length];
}

void IntArray::reset()
{
	if (m_data != nullptr) delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}


void IntArray::resize(const int& length)
{
	int* new_data = new int[length];
	for (int i = 0; i < length; ++i)
	{
		new_data[i] = m_data[i];
	}
	m_data = new_data;
	m_length = length;

}
void IntArray::insert_before(const int& value, const int& idx)
{
	// O(N) target
	resize(m_length + 1);
	int temp;
	for (int i = idx; i < m_length; ++i)
	{
		temp = m_data[i+1];
		m_data[i + 1] = m_data[idx];
		m_data[idx] = temp;
	}
	m_data[idx] = value;
}

void IntArray::remove(const int& idx)
{
	for (int i = idx; i < m_length-1; ++i)
	{
		m_data[i] = m_data[i + 1];
	}
	resize(m_length - 1);
}

void IntArray::push_back(const int& value)
{
	resize(m_length + 1);
	m_data[m_length - 1] = value;
}

int& IntArray::operator[](int i)
{
	return m_data[i];
}

IntArray& IntArray::operator=(const IntArray& int_array)
{
	if (this == &int_array) return *this;
	delete[] m_data;
	m_length = int_array.m_length;
	if (int_array.m_data != nullptr)
	{
		m_data = new int[m_length];
		for (int i = 0; i < m_length; ++i)
			m_data[i] = int_array.m_data[i];
	}
	else
		m_data = nullptr;
}

ostream& operator << (ostream& out, IntArray& arr)
{
	for(int i=0; i < arr.m_length; ++i)
		out << arr.m_data[i] << " ";
	out << endl;
	return out;
}