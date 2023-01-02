#include<iostream>
using namespace std;

float SquareRoot(int n,int p){
    int low=0;
    int high=n/2;
    float ans=0;
    //Integer part
    while(low<=high){
        int mid=(low+high)/2;
        if(mid*mid == n){
            ans=mid;
            break;
        }
        else if(mid*mid < n){
            ans=mid;
            low=mid+1;
        }
        else if(mid*mid > n)
            high=mid-1;
    }
    
    //Floating part
    float inc=0.1;
    for(int i=0;i<p;i++){
        while(ans*ans <= n){
            ans+=inc;
        }
        ans-=inc; 
        inc/=10;
    }
    return ans;
}

int main(){
    int n,p;
    cin>>n>>p;
    cout<<SquareRoot(n,p)<<endl;
    return 0;
}