#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter k : ";
    cin>>k;
    // n=n^(1<<k);  makes set bit unset
    n=n|(1<<k);
    cout<<n<<endl;
    return 0;
}