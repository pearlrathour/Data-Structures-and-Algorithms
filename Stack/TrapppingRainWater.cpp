#include <bits/stdc++.h>
using namespace std;

int trap1(vector<int> &height){
    int n = height.size();
    vector<int> lmax(n), rmax(n);
    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];
    for (int i = 1; i < n; i++)
        lmax[i] = max(lmax[i - 1], height[i]);
    for (int i = n - 2; i >= 0; i--)
        rmax[i] = max(rmax[i + 1], height[i]);

    int ans = 0;
    for (int i = 0; i < n; i++){
        int m = min(lmax[i], rmax[i]);
        if (height[i] < m)
            ans += m - height[i];
    }
    return ans;
}

int trap(vector<int> &height){
    int n = height.size();
    int l = 0, r = n - 1, lmx = 0, rmx = 0, ans = 0;
    while (l <= r) {
        if (height[l] <= height[r]){
            if (height[l] > lmx)
                lmx = height[l];
            else
                ans += (lmx - height[l]);
            l++;
        }
        else{
            if (height[r] > rmx)
                rmx = height[r];
            else
                ans += (rmx - height[r]);
            r--;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << trap(arr) << endl;
    return 1;
}