//Remove duplicates from sorted array

#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
        int s=nums.size();
        if(s==1)
            return 1;
        int l=1;
        for(int i=0 ; i<s-1; i++)
            if(nums[i]!=nums[i+1]){
                nums[l]=nums[i+1];
                l++;
            }
        return l;
    }

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    cout << endl;

    int l = removeDuplicates(A);

    
    for (int i = 0; i < l; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}