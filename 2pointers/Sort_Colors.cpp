#include <bits/stdc++.h>
using namespace std;

void sortColors(vector<int> &nums)
{
    int l = nums.size();
    int low = 0, mid = 0, high = l - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout<<endl;
    sortColors(A);
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}