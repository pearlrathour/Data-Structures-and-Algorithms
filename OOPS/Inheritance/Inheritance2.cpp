#include<iostream>
using namespace std;

class base{
    public:
    base(){         
        cout<<"Default Base "<<endl;
    }
    base(int x){         
        cout<<"Param Base "<<x<<endl;
    }
};

class derived : private base{        
    public:
    derived(){         
        cout<<"Default Derived "<<endl;
    }
    derived(int x,int a):base(x){         
        cout<<"Param Derived "<<a<<endl;
    }
};
int main(){
    //derived c(5);
    derived c;
    return 0;
}