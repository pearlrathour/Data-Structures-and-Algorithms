#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>> &intrv)
{
    int n = intrv.size();
    if (n == 1)
        return intrv;

    sort(intrv.begin(), intrv.end());
    vector<vector<int>> ans;
    int l = intrv[0][0], r = intrv[0][1];

    for (int i = 1; i < n; i++){
        if (intrv[i][0] >= l && intrv[i][0] <= r){
            if (intrv[i][1] >= r)
                r = intrv[i][1];
        }
        else{
            vector<int> a = {l, r};
            ans.push_back(a);
            l = intrv[i][0];
            r = intrv[i][1];
        }
    }
    vector<int> a = {l, r};
    ans.push_back(a);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n,vector<int>(2));
    for (int i = 0; i < n; i++)
        cin >> A[i][0]>>A[i][1];

    for (int i = 0; i < n; i++)
    {
        cout <<"["<< A[i][0] << ","<< A[i][1]<<"] ";
    }
    cout<<endl;
    vector<vector<int>>ans = merge(A);
    for (int i = 0; i < 1; i++){
        cout <<"["<< ans[i][0] << ","<< ans[i][1]<<"] ";
    }
    return 0;
}