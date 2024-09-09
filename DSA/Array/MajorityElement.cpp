#include <bits/stdc++.h>
using namespace std;

//O(nlogn)
int majorityElement(int n, vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[n/2];
}

// Moore's Voting Algo
// O(n)
int fun(int n, vector<int> &nums){
    int count = 0;
    int candidate = 0;

    for (int num : nums){
        if (count == 0)
            candidate = num;
        if (num == candidate)
            count++;
        else
            count--;
    }

    return candidate;
}

int main(){
    int n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout << fun(n, v) << endl;
    return 0;
}
