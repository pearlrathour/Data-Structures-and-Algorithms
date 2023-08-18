#include <iostream>
#include <chrono>
using namespace std;
int main(){
    cout << "Enter the number of elements you want to test for" << endl;
    int n;
    cin >> n;
    int arr[n];
   for (int i = 0; i < n; i++){
        arr[i] = i + 1;
    }
    float average = 0;
    float sum = 0;
    double a[n];    
    auto start1 = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    for (int i = 0; i < n; i++){
        sum = 0;
        for (int j = 0; j <= i; j++){
            sum += arr[j];
        }
        average = sum / (i + 1);
        a[i] = average;
    }
    auto stop1 = chrono::high_resolution_clock::now();
    auto duration1 = chrono::duration_cast<chrono::milliseconds>(stop1 - start1);

    cout << "Time taken by function 1 : " << (duration1.count()) * 1e9 << " milliseconds"
         << "\n";
    sum = 0;
    average = 0;
    auto start2 = chrono::high_resolution_clock::now();
    for (int i = 0; i < n; i++){
        sum += arr[i];
        average = sum / (i + 1);
        a[i] = average;
    }
    auto stop2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::milliseconds>(stop2 - start2);
    cout << "Time taken by function 2 : " << duration2.count() << " milliseconds"
         << "\n";

    return 0;
}
