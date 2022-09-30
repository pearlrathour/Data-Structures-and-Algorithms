#include<iostream>
using namespace std;

int sum(int N){
    if(N<10)
        return N;
    return N%10 +sum(N/10);
}

int main(){
    int N;
    cin>>N;
    cout<<sum(N);
    return 1;
}