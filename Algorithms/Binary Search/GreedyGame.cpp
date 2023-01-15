#include <iostream>
using namespace std;
 
bool divideAmongK(int arr[],int n,int k,int limit){
    //return true if every partition gets atleast limit no of coins
 
        int cnt = 0;
        int current_sum = 0;
        
        for(int i=0;i<n;i++){
            if(current_sum + arr[i] >=limit){
                cnt +=1;
                current_sum = 0;
            }
            else{
                current_sum += arr[i];
            }
        } 
       
    return cnt>=k;
}
 
int k_partition(int arr[],int n,int k){
   
    int high = 0;
    int low = 0;
    for(int i=0; i<n; i++)
        high+= arr[i];
        
        
    int mid;
    int ans;
    
    while(low <= high){
         mid = (low+high)/2;
         
        bool isPossible = divideAmongK(arr,n,k,mid);
        
        if(isPossible){
            low = mid + 1;
            ans = mid;
        }
        else{
            high = mid - 1;
        }
    }
    return ans;
 
}
int main() {
    int a[] = {1,2,3,4};
    int n  = sizeof(a)/sizeof(int);
    int k = 3;
    cout<< k_partition(a,n,k)<<endl;
    return 0;
}