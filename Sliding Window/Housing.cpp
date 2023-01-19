#include<bits/stdc++.h>
using namespace std;

//burte force
//O(n**2)

void housing1(vector<int>&P, int n, int k){
    for(int i=0; i<n; i++){
        int sum=0;
        for(int j=i; j<n; j++){
            sum+=P[j];
            if(sum==k){
                cout<<i<<" "<<j<<endl;
                break;
            }
            if(sum>k)
                break;
        }
    }
}



//prefix sum
//O(n + nlogn)

int pos(vector<int>&P, int n,int i,int d){
    int low=i,high=n;
    int mid;

    while(low<=high){
        mid=(high-low)/2 + low;

        if(P[mid]==d)
            return mid;
        else if(P[mid]>d)
            high=mid-1;
        else
            low=mid+1;
    }
    return -1;
}

void housing2(vector<int>&P, int n, int k){
    int s=0;
    for(int i=0; i<n; i++){
        s+=P[i];
        P[i]=s;
    }
    int d;
    for(int i=0; i<n; i++){
        d=k+P[i];
        int p=pos(P,n,i,d);

        if(p!=-1)
            cout<<i+1<<" "<<p<<endl;
    }
}


//sliding window
//O(n)

void housing3(vector<int>&P, int n, int k){
    int i=0,j=0;
    int sum=0;

    while(j<n){
        //expand window to right
        sum+=P[j];
        j++;
        
        //collapse window from left
        while(sum>k && i<j){
            sum-=P[i];
            i++;
        }

        if(sum==k)
            cout<<i<<" "<<j-1<<endl;
    }
}


int main(){
    int n,k;
    cin>>n>>k;
    vector<int>plots(n);
    for(int i=0; i<n; i++)
        cin>>plots[i];
    housing1(plots,n,k);
    cout<<"Brute force"<<endl<<endl;

    housing2(plots,n,k);
    cout<<"Prefix Sum"<<endl<<endl;

    housing3(plots,n,k);
    cout<<"Sliding Window"<<endl<<endl;
    return 0;
}