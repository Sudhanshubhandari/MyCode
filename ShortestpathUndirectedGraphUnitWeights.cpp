#include <bits/stdc++.h>

using namespace std;

vector<int> adj[3];
void BFS(int N, int src)
{
	int dist[N];
	for (int i = 1; i <= N; i++) dist[i] = INT_MAX;
	queue<int>  q;

	dist[src] = 0;
	q.push(src);

	while (!q.empty())
	{
		int node = q.front();
		q.pop();

		for (auto it : adj[node]) {
			if (dist[node] + 1 < dist[it]) {
				dist[it] = dist[node] + 1;
				q.push(it);
			}
		}
	}
	for (int i = 1; i <= N; i++) cout << i << " " << dist[i] << endl;

}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	adj[1].push_back(2);
	adj[2].push_back(1);
	adj[2].push_back(3);
	adj[3].push_back(2);
	adj[3].push_back(1);
	adj[1].push_back(3);



	BFS(3, 1);

}