#include <bits/stdc++.h> 
using namespace std;

//Memoization O(n), O(n)
int sub(int i, int sum, vector<int>& dp, vector<int>& nums){
    if(dp[i]!=-1) return dp[i];
    if(i<0) return 0;
    if(i==0) return dp[i]=nums[i];

    int pick=nums[i] + sub(i-2,sum,dp,nums);
    int nonpick=sub(i-1,sum,dp,nums);

    return dp[i]=max(pick,nonpick);
}

//Tabulation O(n), O(n)
int sub(int i, int sum, vector<int>& dp, vector<int>& nums){
    dp[0]= nums[0];
    int n=nums.size();
    for(int i=1 ;i<n; i++){
        int pick = nums[i];
        if(i>1)
            pick += dp[i-2];
        int nonPick = 0+ dp[i-1];
        
        dp[i]= max(pick, nonPick);
    }
    return dp[n-1];
}

//O(n) O(1)
int solve(int n, vector<int>& arr){
    int prev = arr[0];
    int prev2 =0;
    
    for(int i=1; i<n; i++){
        int pick = arr[i];
        if(i>1)
            pick += prev2;
        int nonPick = 0 + prev;
        
        int cur_i = max(pick, nonPick);
        prev2 = prev;
        prev= cur_i;
        
    }
    return prev;
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n=nums.size(), sum=0;
    vector<int>dp(n,-1);
    return sub(n-1,0,dp,nums);
}


int main(){
    int N;
    cin>>N;
    vector<int>A(N);
    for(int i=0; i<N; i++)
        cin>>A[i];
    cout<<maximumNonAdjacentSum(A)<<endl;
    return 0;
}