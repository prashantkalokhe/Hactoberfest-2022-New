#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<int>&low, vector<int>&disc, vector<int> adj[], vector<int>&parent, vector<pair<int, int>>&bridge){

	static int timer = 0;
	disc[node] = low[node] = timer;
	timer++;

	for(auto it:adj[node]){
		if(disc[it] == -1){
			parent[it] = node;
			DFS(it, low, disc, adj, parent, bridge);
			low[node] = min(low[node], low[it]);

			if(low[it]>disc[node]){
				bridge.push_back({node, it});
			}
		}
		else if(it != parent[node]){
			low[node] = min(low[node], disc[it]);
		}
	}

}