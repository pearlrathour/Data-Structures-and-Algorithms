#include<iostream>
using namespace std;

void print(int n){
    if(n==0)
        return;
    print(n-1);
    cout<<n<<endl;
}

void print_rev(int n){
    if(n==0)
        return;
    cout<<n<<endl;
    print_rev(n-1);
}

int main(){
    int n;
    cin>>n;
    cout<<"1 to N : "<<endl;
    print(n);
    cout<<"N to 1 : "<<endl;
    print_rev(n);
    return 0;
}