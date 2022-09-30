#include <iostream>
using namespace std;

int linear_search(int a[],int n,int val){
    for(int i=0 ; i<n ; i++){
        if(a[i]==val)
            return i;
    }
    return -1;
}

void insert(int a[],int n,int k,int val){
    int j=n;
    while(j>=k){
        a[j+1]=a[j];
        j--;
    }
    a[k]=val;
    n=n+1;
}

void del(int a[],int n,int k){
    int j=k;
    while(j<n){
        a[j]=a[j+1];
        j++;
    }
    n=n-1;
}

void bubblesort(int arr[],int n){ 
    for (int i = 0; i < n; i++){
        for (int ptr = 0; ptr < n - i - 1; ptr++){
            if (arr[ptr] > arr[ptr + 1])
            {
                swap(arr[ptr], arr[ptr + 1]);
            }
        }
    }
} 

void merge(){

}

void display(int a[],int n){
    for(int i=0 ; i<n ; i++)
        cout<<a[i]<<" ";
}


int main()
{
    int a[]={9,4,0,1,2,8};
    int n = sizeof(a) / sizeof(a[0]);

    int usrchoice=0;
    int val, k;

    while (1){
        cout << "\n\n1.Search 2.Insert 3.Delete 4.Sort 5.Merge 6.Display 7.Exit\n"<< endl;

        cout << "Enter the choice of operation to be implemented"<< endl;
        cin >> usrchoice;

        switch (usrchoice){
        case 1:
            cout << "Enter Value to be searched" << endl;
            cin >> val;
            cout<<val<<" is at index "<<linear_search(a,n,val);
            break;

        case 2:
            cout << "Enter Value to be entered" << endl;
            cin >> val;
            cout << "Enter index : " << endl;
            cin >> k;
            insert(a,n,k,val);
            display(a,n);
            break;

        case 3:

            cout << "Enter index : " << endl;
            cin >> k;
            del(a,n,k);
            display(a,n);
            break;

        case 4:
            bubblesort(a,n);
            display(a,n);
            break;

        case 5:
            merge();
            break;

        case 6:
            cout<<"Array : "<<endl;
            display(a,n);
            break;

        case 7:
             exit(1);

        default:
            cout<<"Enter a valid choice : ";
            break;
           
        }
    }

    return 0;
}