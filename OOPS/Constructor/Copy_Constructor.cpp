#include <iostream>
#include <string.h>
using namespace std;
class student{
    int rno;

public:
    student(){};
    
    student(int r){
        rno=r;
    }

    //inbuilt shallow
    student(student const &t){
        cout<<"Copy constructor called"<<endl;
        rno = t.rno;
    }

    void display(){
        cout<<rno<<endl;
    }
};

int main(){
    student z(40),z1;
    z.display();

    z1=z;    // Copy Cons not called
    z1.display();

    student z2=z;    // Copy Cons called
    z2.display();

    return 0;
}
