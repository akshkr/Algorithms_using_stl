#include <bits/stdc++.h>
using namespace std;

vector <int> V[10001];
int vis[10001];

void dfs(int v) {
	if(!vis[v]) {
		vis[v] = 1;
		printf("%d\n", v);
		for(int i = 0; i < V[v].size(); i++) {
			dfs(V[v][i]);
		}
	}
}

int main() {
	int nodes, edges;
	cin >> nodes >> edges;
	for(int i = 0; i < edges; i++) {
		int u, v;
		cin >> u >> v;
		V[u].push_back(v);
		V[v].push_back(u);
	}

	for(int i = 1; i <= nodes; i++) {
		if(!vis[i]) {
			dfs(i);
		}
	}
	return 0;
}