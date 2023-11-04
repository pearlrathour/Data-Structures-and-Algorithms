#include <bits/stdc++.h>
#include <cmath>
using namespace std;

void calculateStats(int tm, int tp, int &te, double &variance, double &stdDev)
{
    te = (tm + 4 * tp + tm) / 6;
    variance = ((tp - tm) * (tp - tm)) / 36.0;
    stdDev = sqrt(variance);
}
int main()
{
    int tm[] = {12,5,15,2,14,5,4,5,12};
    int tp[] = {21,14,30,3,17,14,12,7,14,21};
    int te;
    double variance, stdDev;
    cout << "Activity\t"
         << "Te\t"
         << "Variance\t"
         << "Standard Deviation\t"
         << "\n";
    for (int i = 0; i < 10; i++)
    {
        calculateStats(tm[i], tp[i], te, variance, stdDev);
        cout << char('A' + i) << "\t\t" << te << "\t" << variance << "\t\t" << stdDev << "\t\t" << endl;
    }
    return 0;
}