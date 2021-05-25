
#include<iostream>
#include<vector>
using namespace std;

int n, cnt=0;
vector<int> adj[1005];
int ver[1005];

void dfs(int x) {
	ver[x] = 1;
	for (int i = 0; i < adj[x].size(); i++) {
		if (!ver[adj[x][i]]) dfs(adj[x][i]);
	}
}


int main() {
	int e;
	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		adj[t1].push_back(t2);
		adj[t2].push_back(t1);
	}
	for (int i = 1; i <= n; i++) {
		if (!ver[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
	return 0;
}