#include <bits/stdc++.h>
using namespace std;

//Memoization O(n*4*3) O(N)+O(N*4)
int f(int day, int last, vector<vector<int>>& points, vector<vector<int>>& dp){
    if(day==0){
        int maxi=0;
        for(int i=0; i<3; i++){
            if(i!=last)
                maxi=max(maxi, points[0][i]);
        }
        return maxi;
    }

    if(dp[day][last]!=-1)
        return dp[day][last];

    int maxi=0;
    for(int i=0; i<3; i++){
        if(i!=last){
            int point=points[day][i] + f(day-1,i,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    vector<vector<int>>dp(n, vector<int>(4,-1));
    return f(n-1,3,points,dp);
}


//Tabulation O(N*4*3) O(N*4)
int ninjaTraining1(int n, vector<vector<int>> &points){
    vector<vector<int>>dp(n, vector<int>(4,-1));
    dp[0][0]=max(points[0][1], points[0][2]);
    dp[0][1]=max(points[0][0], points[0][2]);
    dp[0][2]=max(points[0][1], points[0][0]);
    dp[0][3]=max(points[0][0], points[0][1], points[0][2]);

    for(int day=1; day<n; day++){
        for(int last=0; last<4; last++){
            dp[day][last]=0;
            int maxi=0;

            for(int task=0; task<3; task++){
                if(task!=last)
                    maxi=max(maxi, points[day][task]+ dp[day-1][task]);
            }
        }
    }
    return dp[n-1][3];
}

//Space Optmiisatiom O(N*4*3) O(4)
int ninjaTraining2(int n, vector<vector<int>> &points){
    vector<int>prev(4);
    prev[0]=max(points[0][1], points[0][2]);
    prev[1]=max(points[0][0], points[0][2]);
    prev[2]=max(points[0][1], points[0][0]);
    prev[3]=max(points[0][0], points[0][1], points[0][2]);

    for(int day=1; day<n; day++){
        vector<int>temp(4);
        for(int last=0; last<4; last++){
            temp[last]=0;

            for(int task=0; task<3; task++){
                if(task!=last)
                    temp[last]=max(temp[last], points[day][task]+ prev[task]);
            }
        }
        prev=temp;
    }
    return prev[3];
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>>points(n,vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cin>>points[i][j];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++)
            cout<<points[i][j]<<" ";
        cout<<endl;
    }
    cout<<ninjaTraining(n,points);
    return 0;
}