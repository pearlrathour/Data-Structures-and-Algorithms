#include<bits/stdc++.h>
using namespace std;

bool isPowerOfTwo(int n)
{
    return (ceil(log2(n)) == floor(log2(n)));
    //ceil(2.3)=3  floor(2.3)=2
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    if(n==1)
        cout<<"Number is a power of 2"<<endl;
    else if((n&1)==0)
        cout<<"Number is a power of 2"<<endl;
    else
        cout<<"Number is a Not power of 2"<<endl;

    isPowerOfTwo(n) ? cout << "Yes" << endl : cout << "No" << endl;

    return 0;
}