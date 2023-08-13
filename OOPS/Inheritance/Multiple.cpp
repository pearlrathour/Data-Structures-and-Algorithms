#include<iostream>
using namespace std;

class base1{
    public:
        int salary=900;
};

class base2{
    public:
        int bonus=100;
};

class derived : public base1, public base2{        
    public:
        void sum(){
            cout<<"Total "<<salary+bonus<<endl;
        }
};
int main(){
    derived x;
    cout<<x.salary<<" "<<x.bonus<<endl;
    x.sum();
    return 0;
}