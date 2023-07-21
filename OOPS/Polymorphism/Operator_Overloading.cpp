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
	
    // Complex add(Complex const &obj) {
	// 	Complex res;
	// 	res.real = real + obj.real;
	// 	res.img = img + obj.img;
	// 	return res;
	// }

	Complex operator + (Complex const &obj) {
		Complex res;
		res.real = real + obj.real;
		res.img = img + obj.img;
		return res;
	}
	void print() { cout << real << " + i" << img << '\n'; }
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3 = c1 + c2;
    // Complex c3=c1.add(c2);
	c3.print();
}
