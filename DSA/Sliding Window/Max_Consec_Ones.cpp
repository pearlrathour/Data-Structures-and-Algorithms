#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k){
    int n = nums.size(), i = 0, j = 0;
    int zero = 0, one = 0, ml = 0;

    while (j < n){
        if (nums[j++])
            one++;
        else
            zero++;

        if (zero > k){
            if (nums[i] == 0)
                zero--;
            i++;
        }

        ml = max(ml, j - i);
    }
    return ml;
}

int main(){
    int n,k;
    cin >> n>> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<longestOnes(nums,k)<<endl;
    return 0;
}