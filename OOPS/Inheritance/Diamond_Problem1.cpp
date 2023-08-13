#include<iostream>
using namespace std;

class base{
    public:
        int salary=900;
};

class derived1: virtual public base{
    public:
        int bonus=100;
};

class derived2 : virtual public base{        
    public:
        int inc=400;
};

class derived3 : public derived1, public derived2{        
    public:
        void sum(){
            cout<<salary+bonus+inc<<endl;
        }
};
int main(){
    derived3 x;
    cout<<x.salary<<" "<<x.bonus<<" "<<x.inc<<endl;
    x.sum();
    return 0;
}