#include<bits/stdc++.h>
using namespace std;


void find_topo(int node, stack<int> &st, vector<pair<int, int>>adj[], vector<int> &vis){
	vis[node] = 1;
	while(!st.empty()){
		for(auto it: adj[node]){
			if(!vis[it.first]){
				find_topo(it.first, st, adj, vis);
			}
		}
	}
	st.push(node);

}

void ShortestPath(int V, int src, vector<pair<int, int>> adj[]){
	int vis[V] = {0};
	stack<int> st;
	for(int i=0; i<V; i++){
		if(!vis[i]){
			find_topo(i, st, adj, vis);
		}
	}
	int dis[V];
	for(int i=0; i<V; i++){
		dis[i] = 1e9;
	}
	dis[src] = 0;

	while(!st.empty()){
		int node = st.top();
		st.pop();

		if(dis[node] != INF){
			for(auto it: adj[node]){
				if(dis[node]+it.second < dis[it.first]){
					dis[it.first] = dis[node]+it.second;
				}
			}
		}	
	}

	for(int i=0; i<V; i++){
		(dis[i] == INF) ? cout<<"INF " : cout<<dis[i]<<" ";
	}
}

int main(){

	int V, m;
	cin>>V>>m;

	vector<pair<int, int>> adj[V];

	for(int i=0; i<m; i++){
		int u, v, wt;
		cin>>u>>v>>wt;
		adj[u].push_back({v, wt});

	}

}