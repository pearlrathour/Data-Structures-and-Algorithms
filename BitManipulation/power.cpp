#include <bits/stdc++.h>
using namespace std;

double Power(int x, int n)
{
    if (n == 0)
        return 1;

    if (n < 0) { 
            n = abs(n);
            x = 1/x;
        }
        if(n%2==0){
            return Power(x*x,n/2);
        
        }else{
            return x*Power(x*x,n/2);
        }
}

int main()
{
    int n, x;
    cout << "Enter number : ";
    cin >> x;
    cout << "Enter power : ";
    cin >> n;
    cout << Power(x, n) << endl;
    return 0;
}