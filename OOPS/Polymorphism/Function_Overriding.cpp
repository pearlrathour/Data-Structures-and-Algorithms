#include <iostream>
using namespace std;

class Parent {
public:
	void fun(){
		cout << "Base Function" << endl;
	}
};

class Child : public Parent {
public:
	void fun(){
		cout << "Derived Function" << endl;

		// Parent::fun();
	}
};

int main()
{
	Child Child_Derived;
    Child_Derived.fun();
    Child_Derived.Parent::fun();
	// Parent* ptr = &Child_Derived;
    Child* ptr = &Child_Derived;
	ptr->fun();
	return 0;
}
