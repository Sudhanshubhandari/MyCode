#include<bits/stdc++.h>
using namespace std;

int parent[10000];
int rank[10000];

void makeset() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
		rank[i] = 0;
	}
}
int findpar(int node) {
	if (node == parent[node]) {
		return node;
	}
	return parent[node] = findpar(parent[node]); //for the path compression
}

void union(int u, int v) {
	u = findpar(u);
	v = findpar(v);
	if (rank[u] < rank[v]) {
		parent[u] = v;
	}
	else if (rank[v] < rank[u]) {
		parent[v] = u;
	}
	else {
		parent[v] = u;
		rank[u]++;
	}
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	makeset();
	int m;
	cin >> m;
	while (m--) {
		int u, v;
		union(u, v);
	}
	//if 2 or 3 belongs to same component or not
	if (findpar(2) != findpar(3)) {
		cout << "Different Component";
	}
	else {
		cout << "Same";
	}