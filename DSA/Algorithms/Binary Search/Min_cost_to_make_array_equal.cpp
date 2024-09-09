
// You are given two 0-indexed arrays nums and cost consisting each of n positive integers. You can do the following operation any number of times:
// Increase or decrease any element of the array nums by 1.
// The cost of doing one operation on the ith element is cost[i].
// Return the minimum total cost such that all the elements of the array nums become equal.

#include <bits/stdc++.h>
using namespace std;

long helper(vector<int> &nums, vector<int> &cost, int val){
    long ans = 0;
    for (int i = 0; i < nums.size(); i++)
        ans += 1l * abs(nums[i] - val) * cost[i];

    return ans;
}

long long minCost(vector<int> &nums, vector<int> &cost){
    int a = nums[0], b = nums[0];
    for (int i : nums){
        a = min(a, i);
        b = max(b, i);
    }

    long ans = 0;

    while (a < b){
        int mid = (b - a) / 2 + a;
        long cost1 = helper(nums, cost, mid);
        long cost2 = helper(nums, cost, mid + 1);
        if (cost1 > cost2){
            a = mid + 1;
            ans = cost2;
        }
        else{
            b = mid;
            ans = cost1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n), cost(n);

    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < n; i++)
        cin >> cost[i];
    
    cout<<"nums : ";
    for (int i = 0; i < n; i++)
        cout<< nums[i]<<" ";
    cout<<endl;
    cout<<"cost : ";
    for (int i = 0; i < n; i++)
        cout<< cost[i]<<" ";
    cout<<endl;

    cout<<minCost(nums,cost);
    return 0;
}