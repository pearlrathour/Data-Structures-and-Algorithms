#include <iostream>
using namespace std;

class Empty {
};
class Derived : Empty {
	int a;
};
class Derived1 : public Empty {
};
 class Derived2 : virtual public Empty {          
};
 class Derived3 : public Empty {
    char c;
};
class Derived4 : virtual public Empty {
    char c;
};
class Dummy1 {
    char c;
};
class Dummy2 {
    string c;
};

int main()
{
    cout <<"sizeof(Empty) "<<sizeof(Empty)<< endl;
	cout <<"sizeof(Derived) "<<sizeof(Derived)<< endl;
    cout << "sizeof(Derived1) " << sizeof(Derived1) << endl;
    cout << "sizeof(Derived2) " << sizeof(Derived2) << endl;
    cout << "sizeof(Derived3) " << sizeof(Derived3) << endl;
    cout << "sizeof(Derived4) " << sizeof(Derived4) << endl;
    cout << "sizeof(Dummy1) " << sizeof(Dummy1) << endl;
    cout << "sizeof(Dummy2) " << sizeof(Dummy2) << endl;
	return 0;
}
