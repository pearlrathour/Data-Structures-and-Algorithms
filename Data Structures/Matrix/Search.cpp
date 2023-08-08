#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r=matrix.size(), c=matrix[0].size();
        for(int i=0; i<r; i++){
            if(matrix[i][0] <= target && matrix[i][c-1] >= target){
                int low=0, high=c-1, mid;
                while(low<=high){
                    mid=(high-low)/2 + low;

                    if(matrix[i][mid]==target)
                        return 1;
                    else if(matrix[i][mid] > target)
                        high=mid-1;
                    else
                        low=mid+1;
                }
            }
        }
    return 0;
}


int main(){
    int r,c,t;
    cout<<"Enter r, c, t : ";
    cin>>r>>c;
    vector<vector<int>> grid(r, vector<int>(c));
    
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            cin>>grid[i][j];
        }
    }

    cout<<"\nGrid: \n";
    for(int i=0;i<r;i++){
        for(int j=0; j<c; j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<searchMatrix(grid, t);
    
    return 0;
}