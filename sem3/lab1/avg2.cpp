#include<iostream>
#include<chrono>
using namespace std;
using namespace std::chrono;

int main()
{
    
    cout << "Enter the number of elements you want to test for" << endl;
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }


    float average = 0;
    float sum = 0;
    double a[n];

    auto start = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        average = sum / (i + 1);
        a[i] = average;
    }
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Time taken by function: " << duration.count() << "milliseconds"<< "\n";
    return 0; 
}