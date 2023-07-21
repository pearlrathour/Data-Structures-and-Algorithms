#include<iostream>
using namespace std;

class rectangle{
    private:
    int length;
    int breadth;

    public:
    rectangle(int l=1,int b=1){         
        length=l;
        breadth=b;
    }
    void setlength(int l){
        length=l;
     
    }
    void setbreadth(int b){
        breadth=b; 
    }
    int getlength(){
        return length;
    }
    int getbreadth(){
        return breadth;
    }
    int area(){
        return getlength()*getbreadth();
    }
};

class cuboid : public rectangle{               //publically inheriting from rectangle
    private:
    int height;

    public:
    cuboid(int h){
        height=h;
    }
    int getheight(){
        return height;
    }
    void setheight(int h){
        height=h; 
    }
    int volume(){
        return getlength()*getbreadth()*getheight();
    }
    
};
int main(){
    cuboid c(5);
    c.setlength(2);
    c.setbreadth(8);
    cout<<c.volume();
    return 0;
}