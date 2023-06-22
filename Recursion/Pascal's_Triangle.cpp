#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> generate_rec(int n, vector<int> curr = {1}, vector<vector<int>> res = {})
{
    if (n == 0)
    {
        return res;
    }
    if (curr.size() == 1)
    {
        res.push_back(curr);
        curr.push_back(1);
        return generate_rec(n - 1, curr, res);
    }
    else
    {
        res.push_back(curr);
        vector<int> c1 = {1};
        for (int i = 1; i < curr.size(); i++)
        {
            c1.push_back(curr[i] + curr[i - 1]);
        }
        c1.push_back(1);
        curr = c1;
        return generate_rec(n - 1, curr, res);
    }
}

vector<vector<int>> generate_it(int n)
{
    vector<vector<int>> res;
    for (int i = 0; i < n; i++)
    {
        vector<int> r(i + 1, 1);
        for (int j = 1; j < i; j++)
        {
            r[j] = res[i - 1][j - 1] + res[i - 1][j];
        }
        res.push_back(r);
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans=generate_it(n);
    return 0;
}