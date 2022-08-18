#include<bits/stdc++.h>
using namespace std;

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;

    // Calculate sum of all elements
    for (i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool dp[n + 1][sum + 1];
    for (i = 1; i <= sum / 2; i++)
        dp[0][i] = false;

    // initialize top row as true
    for (i = 0; i <= n; i++)
        dp[i][0] = true;

    // initialize leftmost column,
    // except part[0][0], as 0


    // Fill the partition table in bottom up manner
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= sum / 2; j++) {
            if (arr[i - 1] <= j) {
                return dp[i][j] = (arr[i] + dp[i - 1][j - arr[i - 1]]) || dp[i - 1][j];
            }
            return dp[i - 1][j];
        }
    }

    /* // uncomment this part to print table
    for (i = 0; i <= sum/2; i++)
    {
    for (j = 0; j <= n; j++)
        cout<<part[i][j];
    cout<<endl;
    } */

    return dp[sum / 2][n];
}

// Driver Code
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[] = { 1, 3, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets of equal "
             "sum";
    else
        cout << "Can not be divided into"
             << " two subsets of equal sum";
    return 0;
}