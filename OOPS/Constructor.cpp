#include<iostream>
using namespace std;

class Rectangle{
    private :
    int length;
    int breadth;

    public:
     //constructor overloading(3 diff constructor of same name)

    /*Rectangle(){                      //non-parametireised comstructor
        length=0;                     //will give value and not garbage values in case of Rectangle r()
        breadth=0;
    }
    Rectangle(int l,int b){           //parametireised comstructor
        setlength(l);
        setbreadth(b);
    }*/
    Rectangle(Rectangle &r){        //copy constructor
        length=r.length;
        breadth=r.breadth;
    }

    Rectangle(int l=0,int b=0){         
        setlength(l);
        setbreadth(b);
    }

    //mutators
    void setlength(int l){
        if(l>0)
        length=l;
        else
        length=0;
     
    }
    void setbreadth(int b){
       if(b>0)
        breadth=b;
        else
        breadth=0; 
    }

    //accessors
    int getlength(){
        return length;
    }
    int getbreadth(){
        return breadth;
    }

    //facilitators
    int area(){
        return getlength()*getbreadth();
    }

    //Inspector functions
    bool issquare(){
        return length==breadth;
    }

    //Destructor function
    ~ Rectangle(){
        cout<<"Destructor called"<<endl;
    }
};

int main(){
    Rectangle r1;
    Rectangle r2(3,5);
    Rectangle r3(r2);
    cout<<r1.area()<<endl;
    cout<<r2.area()<<endl;
    cout<<r3.area()<<endl;
    if(r2.issquare())
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    return 0;

}