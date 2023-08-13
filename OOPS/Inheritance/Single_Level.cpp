#include<iostream>
using namespace std;

class base{
    public:
        int salary=900;
};

class derived : public base{        
    public:
        int bonus=100;
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