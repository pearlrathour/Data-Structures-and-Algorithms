// Program to search an ITEM(integer) in an array using binary search,if FOUND then delete that item from array and if NOT FOUND than insert that item in kth position(inout k from user)

#include <iostream>
using namespace std;

int main()
{
    bool change = 0;
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    cout << endl;
    int index_insert = 0;

    int *arr = (int *)malloc((n + 1) * sizeof(int));
    cout << "Enter the elements of the array" << endl;
    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the term to be searched: " << endl;
    int search;
    cin >> search;

//sorting
    for (int i = 0; i < n; i++)
    {
        change = 0;
        for (int j = 0; j <n-i-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                change = 1;
            }
        }
        if (change == 0)
            break;
    }

    cout << "The sorted array is as:" << endl;
    for (int i = 0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int low = 0;
    int high = n - 1;
    int mid = (low + high) / 2 ;
    bool loc = 0;

    if (low == high)
    {
        if (arr[low] == search)
            loc = 1;
    }

    while (low < high)
    {
        if (arr[mid] == search)
        {
            loc = 1;
            cout << "loc at the " << mid + 1 << "location" << endl;
            break;
        }
        else if (arr[mid] < search)
        {
            low = mid + 1;
        }
        else if (arr[mid] > search)
        {
            high = mid - 1;
        }
        mid = (low + high) / 2 ;
    }

    if (loc == 0)
    {
        cout << "The required element is not loc in the array" << endl;
        if (arr[n - 1] <= search)
        {
            arr[n] = search;
        }
        else
        {
        
            for (int i = 0; i < n - 1; i++)
            {
            if (arr[i] <=search && arr[i + 1] >= search)
            {
                index_insert = i+1;
                break;
            }
        }

        int j = n-1;

        while (j >= index_insert)

        {
            arr[j+1] = arr[j];
            j--;
        }

        arr[index_insert] = search;
        }
        
        cout << endl;
        cout << endl;

        cout << "The new array is as with the input search term" << endl;
        for (int i = 0; i <= n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    if(loc==1)
    {
        for(int i=mid;i<n-1;i++)
        {
            arr[i]=arr[i+1];
        }
        cout<<"The array with removed element is as:"<<endl;
        for (int i = 0; i <= n-2; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}