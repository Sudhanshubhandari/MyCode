

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
	int key[N];//node weight
	bool mstSet[N];

	for (int i = 0; i < N; i++) {
		key[i] = INT_MAX;
		mstSet[i] = false;
	}



	// --------BRUTE FORCE-----------------------------------
	// key[0] = 0;
	// parent[0] = -1;

	// for (int j = 0; j < N - 1; j++) {
	// 	int mini = INT_MAX;
	// 	int u;
	// 	for (int k = 0; k < N; k++) {
	// 		if (mstSet[k] == false and key[k] < mini) {
	// 			mini = key[k];
	// 			u = k;
	// 		}

	// 	}
	// 	mstSet[u] = true;
	// 	for (auto it : adj[u]) {
	// 		int k = it.first;
	// 		int weight = it.second;
	// 		if (mstSet[k] == false and weight < key[k]) {
	// 			parent[k] = u;
	// 			key[k] = weight;

	// 		}
	// 	}


	// }

	priority_queue< pair<int, int>, vector <pair<int, int>> , greater<pair<int, int>> > pq;

	key[0] = 0;
	parent[0] = -1;
	pq.push({/*weight*/0, 0});

	while (!pq.empty())
	{
		int u = pq.top().second;
		pq.pop();

		mstSet[u] = true;

		for (auto it : adj[u]) {
			int v = it.first;
			int weight = it.second;
			if (mstSet[v] == false && weight < key[v]) {
				parent[v] = u;
				key[v] = weight;
				pq.push({key[v], v});
			}
		}
	}

	for (int i = 1; i < N; i++)
		cout << parent[i] << " - " << i << " \n";
	return 0;
}