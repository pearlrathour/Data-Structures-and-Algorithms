#include<iostream>
using namespace std;

class rectangle{
    public:
    int l;
    int b;
    int area(){
        return l*b;
    }
};

int main(){
    rectangle *p;               //object created in heap
    p=new rectangle;
    p->l=2;
    p->b=3;                     //dereference operator

    /* rectangle r1;
    rectangle *p;
    p=&r1;
    p->l=2;
    p->b=3 */
    cout<<p->area()<<endl;
    return 0;
}