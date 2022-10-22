#include<bits/stdc++.h>
using namespace std;


bool detectCycle(int V, vector<int> adj[], vector<int> &vis, int s){
	queue<pair<int, int>>q;

	vis[s] = 1;
	q.push({s, -1});

	while(!q.empty()){
		int node = q.front().first;
		int par = q.front().second;
		q.pop();

		for(int x = 0; x < adj[node].size(), x++){
			if(!vis[adj[node][j]]){
				q.push({adj[node][j], node});
				vis[adj[node][j]] = 1;
			}
			else if(adj[node][j] != par){
				return true;
			}
		}
	}
	return false;
}

bool baseCycle(vector<int> adj[], int V){
	vector<int> vis(V+1, 0);

	for(int i=1; i<=V; i++){
		if(!vis[i]){
			if(detectCycle(V, adj[], vis, i)){
				return true;
			}
		}
	}
	return false;
}