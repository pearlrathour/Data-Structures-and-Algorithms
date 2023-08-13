#include <bits/stdc++.h>
using namespace std;

void subseq(int ind, int n, vector<int> &sub, vector<int> &nums, vector<vector<int>> &res){
    if (ind >= n){
        res.push_back(sub);
        return;
    }
    sub.push_back(nums[ind]);
    subseq(ind + 1, n, sub, nums, res);
    sub.pop_back();
    subseq(ind + 1, n, sub, nums, res);
}

vector<vector<int>> subsets(vector<int> &nums){
    int n = nums.size();
    vector<int> sub;
    vector<vector<int>> res;
    subseq(0, n, sub, nums, res);
    return res;
}

int main(){
    int n, a;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n ";
    vector<vector<int>>res=subsets(A);
    for(auto i : res){
        for(auto j : i){
            cout<<j<<" ";
        }
        cout<<", ";
    }
    return 0;
}