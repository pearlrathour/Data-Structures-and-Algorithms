// Most Stones Removed with Same Row or Column

#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
public:
    vector<int> par, size;
    DisjointSet(int n){
        par.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            par[i] = i;
    }

    int findpar(int node){
        if (node == par[node])
            return node;
        return par[node] = findpar(par[node]);
    }

    void Union(int u, int v){
        int pu = findpar(u);
        int pv = findpar(v);
        if (pu == pv)
            return;
        if (size[pu] < size[pv])
        {
            par[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int longestConsecutive(vector<int> &nums){
    int n = nums.size();
    if (n == 0)
        return {};
    DisjointSet ds(n);
    unordered_set<int> st;
    unordered_map<int, int> id;
    for (int i = 0; i < n; i++){
        id[nums[i]] = i;
        st.insert(nums[i]);
    }

    for (int num : st){
        if (st.count(num - 1))  //if not first element
            continue;
        int curr = num;
        while (st.count(curr + 1)){
            ds.Union(id[curr], id[curr + 1]);
            curr++;
        }
    }

    vector<int> res(n);
    for (int i = 0; i < n; i++)
        res[ds.findpar(i)]++;
    return *max_element(res.begin(), res.end());
}

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i<n; i++) cin>>nums[i];
    cout << longestConsecutive(nums) << endl;
    return 0;
}