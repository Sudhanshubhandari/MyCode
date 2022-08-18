#include<bits/stdc++.h>
using namespace std;
int gcd(int c1, int c2)
{

	return c2 == 0 ? c1 : gcd(c2, c1 % c2);
}
void anssss()
{
	long long n , xx1, xx2;
	cin >> n >> xx1;
	for (int i = 1; i < n; i++)
	{
		cin >> xx2;
		xx1 = gcd(xx1, xx2);
	}
	cout << xx1*n << endl;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {



		anssss();
	}
}