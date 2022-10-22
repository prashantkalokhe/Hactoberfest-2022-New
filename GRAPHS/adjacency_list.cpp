#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;

	vector<pair<int, int>> adj[n+1];
	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);   //in case of undirected graph.
	}
}