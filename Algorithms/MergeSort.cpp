#include <iostream>
using namespace std;

void Merge(int array[], int low, int mid,int high){
    int l = mid - low + 1;
    int r = high - mid;

    int *larr = new int[l],*rarr = new int[r];

    for (int i = 0; i < l; i++)
        larr[i] = array[l + i];
    for (int j = 0; j < r; j++)
        rarr[j] = array[mid + 1 + j];

    int index_larr = 0,index_rarr= 0;  
    int index_mergedarr = 0;

    // Merge the temp arrays back into array[l..r]
    while (index_larr < l && index_rarr < r)
    {
        if (larr[index_larr] <= rarr[index_rarr])
        {
            array[index_mergedarr] = larr[index_larr];
            index_larr++;
        }
        else
        {
            array[index_mergedarr] = rarr[index_rarr];
            index_rarr++;
        }
        index_mergedarr++;
    }
    // Copy the remaining elements of
    // l[], if there are any
    while (index_larr < l)
    {
        array[index_mergedarr] = larr[index_larr];
        index_larr++;
        index_mergedarr++;
    }

    while (index_rarr < r)
    {
        array[index_mergedarr] = rarr[index_rarr];
        index_rarr++;
        index_mergedarr++;
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

    int mid = begin + (end - begin) / 2;
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