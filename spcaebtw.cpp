#include<bits/stdc++.h>
using namespace std;
void upper(string inp, string out) {
	if (inp.size() == 0) {
		cout << out << " ";
		return;
	}
	string out1 = out;
	string out2 = out;
	out1.push_back(inp[0]);
	out2.push_back(toupper(inp[0]));
	inp.erase(inp.begin() + 0);
	upper(inp, out1);
	upper(inp, out2);
	return;

}
int main()
{
	string inp = {'a', 'b', 'c'};
	string out = " ";

	upper(inp, out);
}