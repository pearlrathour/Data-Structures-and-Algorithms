#include <bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int> &nums)
{
    int l = nums.size();
    int maxsum = INT_MIN, sum = 0;
    for (int i = 0; i < l; i++)
    {
        sum += nums[i];
        maxsum = max(maxsum, sum);
        if (sum < 0)
            sum = 0;
    }
    return maxsum;
}

// max sum subarray

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++){
        cout << A[i] << " ";
    }
    cout << maxSubArray(A) << endl;
    return 0;
}