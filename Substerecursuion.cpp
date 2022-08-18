#include<bits/stdc++.h>
using namespace std;
using namespace std;

string solve(string str, string op, set<string>&st) {
    if (str.length() == 0) {
        st.insert(op);
        return op;
    }
    vector<int>op1 = op;
    vector<int>op2 = op;
    op2.push_back(str[0]);
    str.erase(str.begin() + 0);
    solve(str, op1, st);
    solve(str, op2, st);
    return op;
}
// c a ac a ac aa aac
int main() {
    string str;
    cin >> str;
    string op = " ";
    set<string>st;
    solve(str, op, st);
    for (auto it = st.begin(); it != st.end(); ++it)
        cout << *it << " ";
}