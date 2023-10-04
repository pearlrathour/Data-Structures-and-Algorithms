#include <bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>ump;
        ump[0]=1;
        int sum=0, count=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(ump[sum-goal])
                count+=ump[sum-goal];
            ump[sum]++;
        }
        return count;
    }

int main(){
    int n,k;
    cin >> n>> k;
    vector<int> nums(n);
    for(int i=0; i<n; i++)
        cin>>nums[i];
    cout<<numSubarraysWithSum(nums,k)<<endl;
    return 0;
}