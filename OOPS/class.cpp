#include<bits/stdc++.h>
using namespace std;

class Geeks{
    public:                       //access specifier
    string name;                  //data member
    int id;
    void printid();
    void printname(){             //member function
        cout<<"Name is : "<<sizeof(Geeks)<<endl;
    }
};

void Geeks :: printid(){
    cout<<"Id is : "<<id<<endl;
}

int main(){
    Geeks obj1;               //declaring object of class Geeks
    obj1.name="PEARL";        //accessing data member
    obj1.id=1;
    obj1.printid();
    obj1.printname();         //accessing member function
    return 0;

}