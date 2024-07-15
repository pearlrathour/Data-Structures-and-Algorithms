#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums){
    int res = INT_MIN, curr = 0;
    for (int n : nums){
        curr += n;
        res = max(res, curr);
        if(curr < 0)  curr = 0;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<maxSubArray(arr)<<endl;
    return 0;
}