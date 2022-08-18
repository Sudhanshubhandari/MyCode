#include <iostream>
using namespace std;

// function to convert decimal to binary
string decToBinary(int n)
{

    // array to store binary number
    int binaryNum[32];
    string s = " ";
    // counter for binary array
    int i = 0;
    while (n > 0) {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // printing binary array in reverse order
    for (int j = i - 1; j >= 0; j--)
        s += binaryNum[j] + '0';
    return s;
}

// Driver program to test above function
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n = 4;
    string k =  decToBinary(n);
    cout << k;
}