#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int  mean;

    for (int i = 0; i < t; i++)
    {
        cin  >> mean;
        int a = ((mean * 3) / 2) + 1;
        int b = (a / 2) + 1;
        int c = (mean * 3) - a - b;

        cout <<  a << " " << b  << " " << c  << endl;
    }

}
