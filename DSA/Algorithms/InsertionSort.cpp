#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <bits/stdc++.h>
#define ll long long
#define fi(i, a, n) for (int i = a; i < n; i++)
#define fl(i, a, n) for (long long i = a; i < n; i++)
#define print(a)for (auto x : a)cout << x << ' ';cout<<endl;
#define pearl ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
#define MOD 1000000007

void insertionSort(vector<int>& arr, int n){
    int j, val;
    for (int i= 1; i<n; i++){
        val= arr[i];
        for (j= i-1; j>= 0 && arr[j] > val; j--)
            arr[j+1] = arr[j];
        
        arr[j+1] = val;
        print(arr);
    }
}

int main(){
    int n;
    cout << "Enter size : ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    insertionSort(arr, n);
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}