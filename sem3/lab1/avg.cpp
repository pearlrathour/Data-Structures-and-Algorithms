#include<iostream>
#include<chrono>
using namespace std;
using namespace chrono;

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

    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
        average = sum / (i + 1);
        a[i] = average;
    }
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<milliseconds>(stop1 - start1);

    cout << "Time taken by function 1 : " << duration1.count() << " milliseconds"<< "\n";


    auto start2 = high_resolution_clock::now();
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        average = sum / (i + 1);
        a[i] = average;
    }
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Time taken by function 2 : " << duration2.count() << " milliseconds"<< "\n";
    
    return 0; 
}