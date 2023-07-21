// Compile-time Polymorphism
#include <bits/stdc++.h>

using namespace std;
class Display {
public:
	void func(int x){
		cout << "value of x is " << x << endl;
	}
	void func(double z){
		cout << "value of z is " << z << endl;
	}
	void func(int x, int y){
		cout << "value of x and y is "<<x<<", "<< y<< endl;
	}
};

int main(){
	Display obj;
	obj.func(7);
	obj.func(9.132);
	obj.func(85, 64);
	return 0;
}
