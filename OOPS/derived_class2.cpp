#include <iostream>
using namespace std;

class base1{};
class base2{virtual void show(){}};      //adds virtual pointer to each object 

class test1{    };
class test2{virtual void show(){}};

class derv1 : public virtual base1{};
class derv12 : public virtual base2{};

class derv2 : public virtual base2, public test1{};
class derv22 : public virtual base2, public virtual test1{};
class derv222 : public virtual base2, public virtual test2{};

int main()
{
    cout<<"sizeof base1 = "<<sizeof(base1)<<endl;
    cout<<"sizeof base2 = "<<sizeof(base2)<<endl;
    cout<<"sizeof derv1 = "<<sizeof(derv1)<<endl;
    cout<<"sizeof derv12 = "<<sizeof(derv12)<<endl;

    cout<<"sizeof derv2 = "<<sizeof(derv2)<<endl;
    cout<<"sizeof derv22 = "<<sizeof(derv22)<<endl;
    cout<<"sizeof derv222 = "<<sizeof(derv222)<<endl;

}