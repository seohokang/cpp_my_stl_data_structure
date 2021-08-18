#include <iostream>
using namespace std;

class Mother
{
public:
	Mother(const int& i_in)
		:m_i(i_in)
	{
		cout << "Mother constructor called" << endl;
	}
	void set_value(const int& i_in)
	{
		m_i = i_in;
	}
	int get_value()
	{
		return m_i;
	}
private:
	int m_i;
};

class Child : public Mother
{
public:
	Child(const int& i_in, const double& d_in)
		:Mother(i_in), m_d(d_in)
	{
	}
	void set_value(const int& i_in, const double& d_in)
	{
		Mother::set_value(i_in);
		m_d = d_in;

	}
	double get_value()
	{
		return m_d;
	}
private:
	double m_d;
};

int main()
{

	Mother mom(100);
	mom.set_value(100);
	cout << mom.get_value() << endl;
	
	Child child(200, 3.14);
	child.set_value(200);
	cout << child.get_value() << endl;

	child.Mother::set_value(1024);
	return 0;
}