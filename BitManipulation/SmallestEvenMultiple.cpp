// Given a positive integer n, return the smallest positive integer that is a multiple of both 2 and n.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans1=(2*n)/__gcd(2,n);
    int ans2=n << (n & 1);
    cout<<ans1<< endl<< ans2<< endl;
    return 0;
}