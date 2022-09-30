#include<bits/stdc++.h>
using namespace std;

unsigned int countSetBits1(unsigned int n){ 
	unsigned int count = 0; 
	while (n != 0) {
	    if (n % 2 != 0)
	       count++;
	    n = n/2;      
	} 
	return count; 
}

unsigned int countSetBits2(unsigned int n){
    unsigned int count = 0;
    while(n){
        n&=n-1;
        count++;
    }
    return count;
}

unsigned int countSetBits3(unsigned int n){
    unsigned int count = 0;
    while(n>0){
        if(n&1)
            count++;
        n=n/2;
    }
    return count;
}
int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;
    cout<<countSetBits1(n)<<endl;
    cout<<countSetBits2(n)<<endl;
    cout<<countSetBits3(n)<<endl;
    return 0;
}