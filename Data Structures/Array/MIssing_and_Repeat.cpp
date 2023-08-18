#include<bits/stdc++.h>
using namespace std;

void findTwoElement(vector<int> arr, int n) {
        // code here
        long long sum=0;
        sum=accumulate(arr.begin(), arr.end(), sum);
        
        int rep;
        for(int i : arr){
            i=abs(i);
            if(arr[i-1] < 0){
                rep=i;
                break;
            }
            arr[i-1]=-arr[i-1];
        }

        int mis=rep + 1ll*n*(n+1)/2 - sum;
        cout<<rep<<" "<<mis<<endl;
    }
int main(){
    int n;
    cin>>n;
    vector<int>A(n);
    for(int i=0; i<n; i++)
        cin>>A[i];

    for(int i=0; i<n; i++)
        cout<<A[i];
    cout<<endl;

    findTwoElement(A,n);
    return 0;
}