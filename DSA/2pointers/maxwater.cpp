#include<bits/stdc++.h>
using namespace std;
int maxArea(int h[], int n) {
        int left=0, right=n-1;
        int wid=right;
        int maxarea=0,area=0;
        
        for(; wid>0; wid--){
            if(h[left] < h[right]){
                area=wid*h[left];
                left++;
            }
            else{
                area=wid*h[right];
                right--;
            }
            maxarea=max(maxarea, area);    
        }
    return maxarea;
}

int main(){
    int n;
    cin>>n;
    int h[n];
    cout<<"Enter array values : "<<endl;
    for(int i=0; i<n; i++)
        cin>>h[i];
    cout<<maxArea(h,n)<<endl;
    return 0;
}