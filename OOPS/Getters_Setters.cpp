#include<iostream>
using namespace std;

class student{
    private:
        int rollno;
    public:
        int age;
    
        void setrollno(int r){
            rollno=r;
        }
        
        int getrollno(){
            return rollno;
        }
            
    
};

int main(){
    student pearl;
    pearl.age=20;
    // pearl.rollno=55;
    pearl.setrollno(55);
    cout<<pearl.getrollno();
    return 0;
}
