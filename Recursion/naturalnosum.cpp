#include<iostream>
using namespace std;

int sum(int N){
    if(N==0)
        return 0;
    return N+sum(N-1);
}

int main(){
    int N;
    cin>>N;
    cout<<sum(N);
    return 1;
}