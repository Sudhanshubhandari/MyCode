

//What is spanning tree?
//If we can draw a Tree using a graph consisting of n nodes and n-1 edges such that every node is reachable to every othernode in that tree and the cost of the edge weight in the tree is minimum then we can call that is the minimum span tree.


#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int N = 5, m = 6;
	vector<pair<int, int> > adj[N];


	adj[0].push_back({1, 2});
	adj[0].push_back({3, 6});
	adj[1].push_back({0, 2});
	adj[1].push_back({2, 3});
	adj[1].push_back({3, 8});
	adj[1].push_back({4, 5});
	adj[2].push_back({1, 3});
	adj[2].push_back({4, 7});
	adj[3].push_back({0, 6});
	adj[3].push_back({1, 8});
	adj[4].push_back({1, 5});
	adj[4].push_back({2, 7});

	int parent[N];
	int key[N];
	bool mstSet[N];

	for (int i = 0; i < N; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	for (int j = 0; j < N - 1; j++) {
		int mini = INT_MAX;
		int u;
		for (int k = 0; k < N; k++) {
			if (mstSet == false and key[k] < mini) {
				mini = key[k];
				u = k;
			}
			mstSet[u] = true;
			for (auto it : adj[u]) {
				int node = it.first;
				int weight = it.second;
				if (mstSet[node] == false and weight < key[node]) {
					key[node] = weight;
					parent[node] = u;
				}
			}
		}

	}
	for (int i = 0; i < N; i++) {
		cout << parent[i] << "-" << i << "\n";
	}

}