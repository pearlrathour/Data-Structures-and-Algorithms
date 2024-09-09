#include <bits/stdc++.h>
using namespace std;

int trap1(vector<int> &height){
    int s = height.size();
    int water = 0;

    for (int i = 0; i < s; i++){
        int leftmax = 0, rightmax = 0;
        for (int j = i; j >= 0; j--)
            leftmax = max(leftmax, height[j]);
        
        for (int j = i; j < s; j++)
            rightmax = max(rightmax, height[j]);

        water += min(leftmax, rightmax) - height[i];
    }
    return water;
}

int trap2(vector<int>& height) {
    int s=height.size();
    int water=0;
    vector<int>rightmax(s), leftmax(s);

    rightmax[s-1]=height[s-1];
    for(int i=s-2; i>=0; i--)
        rightmax[i]=max(height[i],rightmax[i+1]);
        
    leftmax[0]=height[0];
    for(int i=1; i<s; i++)
        leftmax[i]=max(height[i],leftmax[i-1]);

    for(int i=0; i<s; i++)
        water+=min(leftmax[i], rightmax[i])-height[i];

    return water;
}

int trap3(vector<int>& height) {
    int s=height.size();
    int water=0;
    int left=0, right=s-1, leftmax=0, rightmax=0;

    while(left <= right){
        if(height[left] <= height[right]){
            if(height[left] >= leftmax)
                leftmax=height[left];
            else
                water+=leftmax-height[left];
            left++;
        }
        else{
            if(height[right] >= rightmax)
                rightmax=height[right];
            else
                water+=rightmax-height[right];
            right--;
        }    
    }
    return water;
}

int main()
{
    int n;
    cin >> n;
    vector<int>h(n);
    cout << "Enter heights : " << endl;
    for (int i = 0; i < n; i++)
        cin >> h[i];
    cout << trap3(h) << endl;
    return 0;
}