#include<iostream>
using namespace std;

class base{
    public:
        int salary=900;
};

class derived1: public base{
    public:
        int bonus=100;
};

class derived2 : public derived1{        
    public:
        void sum(){
            cout<<"Total "<<salary+bonus<<endl;
        }
};
int main(){
    derived2 x;
    cout<<x.salary<<" "<<x.bonus<<endl;
    x.sum();
    return 0;
}