#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=1; i<n; i++)
            nums[i]+=nums[i-1];
        
        unordered_map<int,int>ump;
        int ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==k)
                ans++;
            if(ump.find(nums[i]-k)!=ump.end())
                ans+=ump[nums[i]-k];
            ump[nums[i]]++;
        }
        return ans;
    }

int main(){
    int n,k;
    cin >> n>>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << "\n ";
    cout<<subarraySum(A,k);
    return 0;
}