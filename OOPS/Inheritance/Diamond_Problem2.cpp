        //     Parent
        //    /      \
        // Father   Mother
        //    \      /
        //     Child

#include<iostream>
using namespace std;
class Person {
public:
    Person() {
        cout << "Person() called" << endl; 
    }
    Person(int x) {
        cout << "Person(int) called" << endl; 
    }
};
 
class Father : virtual public Person {
public:
    Father(){
       cout << "Father() called" << endl;
    }
    Father(int x){
       cout << "Father(int) called" << endl;
    }
};
 
class Mother : virtual public Person {
public:
    Mother(){
       cout << "Mother() called" << endl;
    }
    Mother(int x){
        cout << "Mother(int) called" << endl;
    }
};
 
class Child : public Father, public Mother { //class Child inherits Father and Mother
public:
    Child(int x){
        cout << "Child(int) called" << endl;
    }
};
 
int main() {
    Child child(30);
    return 0;
}