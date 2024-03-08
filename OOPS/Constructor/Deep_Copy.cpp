#include<bits/stdc++.h>
using namespace std;

class student{
    int age;
    char* name;

    public:
        student(int age, char* name){
            this->age=age;
            this->name=new char[strlen(name)+1];
            strcpy(this->name, name);
        }
        void Display(){
            cout<<age<<" "<<name<<endl;
        }
};

int main(){
    char name[]="abcd";
    int a=19;
    student s1(a,name);
    s1.Display();

    name[0]='x';
    a=20;
    student s2(a,name);
    s2.Display();
    s1.Display();
    return 0;
}