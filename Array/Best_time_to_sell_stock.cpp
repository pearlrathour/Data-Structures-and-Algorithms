#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices)
{
    int l = prices.size(), maxpro = 0;
    int minprice = INT_MAX, idx;

    for (int i = 0; i < l; i++)
    {
        minprice = min(minprice, prices[i]);
        maxpro = max(maxpro, prices[i] - minprice);
    }
    return maxpro;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout<<endl;
    cout << maxProfit(A) << endl;
    return 0;
}
