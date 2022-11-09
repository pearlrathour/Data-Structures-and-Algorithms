#include <bits/stdc++.h>
using namespace std;

vector<int>v;

void Insert(int item){                    
    v.push_back(item);
    long long i = v.size() - 1;
    if (i == 0)
        return;
    else{
        while (v[i] > v[i / 2]){
            swap(v[i], v[i / 2]);
            i = i / 2;
        }
    }
}

void Delete(){
    int res = v[0];
    int n = v.size();
    if (n == 1){
        cout << "Deleted element : " << res << "\n";
        n--;
        return;
    }
    else{
        v[0] = v[n - 1];
        v.pop_back();
        int i = 1;
        while (v[i] > v[i / 2] || v[i + 1] > v[i / 2]){
            if (v[i] > v[i + 1]){
                swap(v[i], v[i / 2]);
                i = 2 * i;
            }
            else{
                swap(v[i + 1], v[i / 2]);
                i = 2 * i + 1;
            }
        }
        cout << "Deleted element : " << res << "\n";
    }
}


void Print(){
    cout << "Priority queue:-\n";
    for (auto x : v)
        cout << x << " ";
    cout << "\n";
}


void Peek(){
    cout << "Max element : " << v[0] << "\n";
}

int main(){
    int num;
    int usrchoice=0;

    while (1){
        cout << "\n\n1.Insert  2.Delete  3.Peek  4.Display  5.Exit" << endl;
		cout << "Enter the choice of operation to be implemented : ";
		cin >> usrchoice;
        
        switch (usrchoice){
        case 1:
            cout<<"Enter val : ";
            cin >> num;
            Insert(num);
            Print();
            break;
        case 2:
            Delete();
            break;
        case 3:
            Peek();
            break;
        case 4:
            Print();
            break;
        case 5:
            exit(1);
        default:
            break;
        }
    }
}
