#include<iostream>
using namespace std;

class Complex {
    private:
	int real,img;
    public:
	Complex(int r = 0, int i = 0){
        real = r;
        img = i;
    }
    void print() { 
        cout << real << " + i" << img << '\n'; 
    }
	friend Complex operator + (Complex c1,Complex c2);
};
Complex operator + (Complex c1,Complex c2) {              //called in main funs
		Complex t;
		t.real = real + t.real;
		t.img = img + t.img;
		return t;
	}
int main(){
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
	c3.print();
}