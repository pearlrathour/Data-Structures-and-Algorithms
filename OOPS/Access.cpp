#include<iostream>
using namespace std;

class base{
    private:
    int a;

    protected:
    int b;

    public:
    int c;
    void funbase(){
        a=1;
        b=2;
        c=3;
    }
};

class derived : base{
    public:
    void funder(){
        //a=10;      private not accessible in derive class
        b=20;
        c=30;
    }
};

int main(){
    base x;
    //x.a=10;        private & protected inaccessible in class object
    //x.b=20;
    x.c=30;
    return 0;
}
