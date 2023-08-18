#include<bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int>& nums) {
        int idx;
        for(auto i : nums){
            idx=abs(i);
            if(nums[idx]<0)
                return idx;
            nums[idx] = -nums[idx];  
        }
        return nums.size();
    }

int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0; i<n; i++)
        cin>>A[i];

    for(int i=0; i<n; i++)
        cout<<A[i];
    cout<<endl;

    cout<<findDuplicate(A);
    return 0;
}