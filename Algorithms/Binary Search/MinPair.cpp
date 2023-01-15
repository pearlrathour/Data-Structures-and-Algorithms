#include<bits/stdc++.h>
using namespace std;

void pairs(vector<int>v1, vector<int>v2){
    sort(v2.begin(),v2.end());

    int diff=INT_MAX;
    int lb;
    int p1,p2;
    
    for(int i : v1){
        lb=lower_bound(v2.begin(), v2.end(), i) - v2.begin();

        //left
        if(lb>=1 && i-v2[lb-1] < diff){
            diff=i-v2[lb-1];
            p1=i;
            p2=v2[lb-1];
        }

        //greater
        if(lb != v2.size() && v2[lb]-i < diff){
            diff=v2[lb]-i;
            p1=i;
            p2=v2[lb];
        }
    }
    cout<<p1<<", "<<p2<<endl;
}

int main(){
    int n1,n2;
    cin>> n1>> n2;
    vector<int>v1(n1);vector<int>v2(n2);
    cout<<"Vector 1 : \n";
    for(int i=0; i<n1; i++)
        cin>>v1[i];
    cout<<"\nVector 2 : \n";
    for(int i=0; i<n2; i++)
        cin>>v2[i];

    pairs(v1,v2);
    return 0;
}