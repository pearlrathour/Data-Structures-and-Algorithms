#include <iostream>
using namespace std;

void Merge(int array[], int const l, int const mid,int const r){
    auto const subarr1 = mid - l + 1;
    auto const subarr2 = r - mid;

    auto *larr = new int[subarr1],*rarr = new int[subarr2];

    for (auto i = 0; i < subarr1; i++)
        larr[i] = array[l + i];
    for (auto j = 0; j < subarr2; j++)
        rarr[j] = array[mid + 1 + j];

    auto indexOfsubarr1 = 0,indexOfsubarr2= 0;  
    int indexOfmergedarr = l;

    // Merge the temp arrays back into array[l..r]
    while (indexOfsubarr1 < subarr1 && indexOfsubarr2 < subarr2)
    {
        if (larr[indexOfsubarr1] <= rarr[indexOfsubarr2])
        {
            array[indexOfmergedarr] = larr[indexOfsubarr1];
            indexOfsubarr1++;
        }
        else
        {
            array[indexOfmergedarr] = rarr[indexOfsubarr2];
            indexOfsubarr2++;
        }
        indexOfmergedarr++;
    }
    // Copy the remaining elements of
    // l[], if there are any
    while (indexOfsubarr1 < subarr1)
    {
        array[indexOfmergedarr] = larr[indexOfsubarr1];
        indexOfsubarr1++;
        indexOfmergedarr++;
    }

    while (indexOfsubarr2 < subarr2)
    {
        array[indexOfmergedarr] = rarr[indexOfsubarr2];
        indexOfsubarr2++;
        indexOfmergedarr++;
    }
    delete[] larr;
    delete[] rarr;
}

// begin is for l index and end is
// r index of the sub-array
// of arr to be sorted */
void MergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursively

    auto mid = begin + (end - begin) / 2;
    MergeSort(array, begin, mid);
    MergeSort(array, mid + 1, end);
    Merge(array, begin, mid, end);
}
int main()
{
    int n;
    cout << "Enter size : ";
    cin >> n;
    int arr[n];
    cout << "Enter elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    MergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}