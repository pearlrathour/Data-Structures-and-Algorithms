#include<bits/stdc++.h>
using namespace std;

int area1(int arr[],int n){
    int res=0;
    for(int i=0;i<n;i++){
        int curr=arr[i];
        for(int j=i-1;j>=0;j--){
            if(arr[j]>=arr[i])
                curr+=arr[i];
            else
                break;
        }
        for(int j=i+1;j<n;j++){
            if(arr[j]>=arr[i])
                curr+=arr[i];
            else
                break;
        }
        res=max(res,curr);
    }
    return res;
}

int area2(int arr[],int n){
    int res=0;
    int ps[n],ns[n];
    
    stack <int> s;
    s.push(0);
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int pse=s.empty()?-1:s.top();
        ps[i]=pse;
        s.push(i);
    }
    
    while(s.empty()==false){
        s.pop();
    }
    
    s.push(n-1);
    for(int i=n-1;i>0;i--){
        while(s.empty()==false && arr[s.top()]>=arr[i])
            s.pop();
        int nse=s.empty()?n:s.top();
        ns[i]=nse;
        s.push(i);
    }
    
    for(int i=0;i<n;i++){
        int curr=arr[i];
        curr+=(i-ps[i]-1)*arr[i];
        curr+=(ns[i]-i-1)*arr[i];
        res=max(res,curr);
    }
    return res;
    
}


int area3(int arr[],int n){
    stack <int> s;
    int res=0;
    int tp;
    int curr;
    
    for(int i=0;i<n;i++){
        while(s.empty()==false && arr[s.top()]>=arr[i]){
            tp=s.top();s.pop();
            curr=arr[tp]* (s.empty() ? i : i - s.top() - 1);
            res=max(res,curr);
        }
        s.push(i);
    }
    while(s.empty()==false){
        tp=s.top();s.pop();
        curr=arr[tp]* (s.empty() ? n : n - s.top() - 1);
        res=max(res,curr);
    }
    return res;
} 
  

int main(){
    int arr[]={6,5,7,2,4,8};
    cout<<area1(arr,6)<<endl;
    cout<<area2(arr,6)<<endl;
    cout<<area3(arr,6)<<endl;
    return 1;
}