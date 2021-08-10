#include <iostream>

class Unit
{
public:
	virtual void attack()
	{
		std::cout << "normal attack" << std::endl;
	}
	void run()
	{
		std::cout << "run code" << std::endl;
		attack();
	}

};

class Marine:public Unit
{
public:
	void attack() override
	{
		std::cout << "marine specfic attack" << std::endl;
	}

};

int main()
{
	// Test1. child class used parent class function to run. if virtual child attack is called even though we use parent function.
	//Unit unit;
	//Marine marine;
	//marine.run();
	
	// Test2. unit is unit. marine is marine
	//Unit unit;
	//Marine marine;
	//Unit* unit1 = &unit;
	//unit.attack();
	//unit1->attack();
	//marine.attack();

	//// Test3. child class used parent class fucntion to run. marine is marine. unit is marine. so if not virtual, unit attack should be called
	//Marine marine;
	//Unit& unit2 = marine;
	//unit2.attack(); // if not virtual marine attack is called
	//marine.attack();
}

