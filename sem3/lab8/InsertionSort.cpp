#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    int val, j;
    for (int i = 1; i < n; i++){
        val = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > val){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = val;
    }
}

int main(){
    int n;
    cout << "Enter size : ";
    cin >> n;
    int arr[n];
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