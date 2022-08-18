#include<bits/stdc++.h>
using namespace std;

struct node {
	int u;
	int v;
	int wt;
	node(int first , int second , int weight) {
		u = first;
		v = second;
		wt = weight;
	}

};

bool comp(node a, node b) {
	return a.wt < b.wt;
}
int findpar(int u, vector<int>&par) {
	if (u == par[u]) {
		return u;
	}
	return  findpar(par[u], par);
}

void unionn(int u, int v, vector<int> &par, vector<int> &rank) {
	u = findpar(u, par);
	v = findpar(v, par);
	if (rank[u] < rank[v]) {
		par[u] = v;
	}
	else if (rank[v] = rank[u]) {
		par[v] = u;
	}
	else {
		par[v] = u;
		rank[u]++;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N = 5, m = 6;
	vector<node> edges;
	edges.push_back(node(0, 1, 2));
	edges.push_back(node(0, 3, 6));
	edges.push_back(node(1, 0, 2));
	edges.push_back(node(1, 2, 3));
	edges.push_back(node(1, 3, 8));
	edges.push_back(node(1, 4, 5));
	edges.push_back(node(2, 1, 3));
	edges.push_back(node(2, 4, 7));
	edges.push_back(node(3, 0, 6));
	edges.push_back(node(3, 1, 8));
	edges.push_back(node(4, 1, 5));
	edges.push_back(node(4, 2, 7));
	sort(edges.begin(), edges.end(), comp);

	vector<int>par(N);
	for (int i = 0; i < N; i++) {
		par[i] = i;
	}
	vector<int>rank(N, 0);
	int cost = 0;
	vector<pair<int, int>>mst;
	for (auto it : edges) {
		if (findpar(it.u, par) != findpar(it.v, par)) {
			cost + it.wt;
			mst.push_back({it.u, it.v});
			unionn(it.u, it.v, par, rank);

		}

	}
	cout << cost << endl;
	for (auto ans : mst) {
		cout << ans.first << "-" << ans.second << endl;
	}
}