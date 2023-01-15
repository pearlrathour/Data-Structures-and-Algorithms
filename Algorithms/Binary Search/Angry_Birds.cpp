#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int B,int N, vector<int>nests, int sep){
    int birds=1;
    int loc=nests[0];

    for(int i=1; i<=N-1; i++){
        int curr=nests[i];
        if(curr - loc >= sep){
            birds++;
            loc=curr;

            if(birds==B)
                return 1;
        }
    }
    return 0;
}

int main(){
    int B,N;
    cin>> B>> N;
    vector<int>nests(N);
    for(int i=0; i<N; i++)
        cin>>nests[i];
    sort(nests.begin(),nests.end());
    int low=0;
    int high=nests[N-1] - nests[0];
    int mid, ans=0;

    while(low<=high){
        mid=(low+high)/2;
        bool canPlace=canPlaceBirds(B,N,nests,mid);

        if(canPlace){
            ans=mid;
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}