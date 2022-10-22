#include<bits/stdc++.h>
using namespace std;


void Atriculation(int node, vector<int> adj[], vector<int>&disc, vector<int>&low,
 					vector<int>&parent, vector<int>&isAtri){

	static int timer=0;
	disc[node] = low[node] = timer;
	timer+=1;
	int child = 0;

	for(auto it: adj[node]){
		if(disc[it] == -1){
			parent[it] = node;
			Atriculation(it, adj, disc, low, parent, isAtri);
			low[node] = min(low[node], low[it]);
			if(low[it] >= disc[node] && parent[node] != -1){
				isAtri[node] = 1;
			} 
			child++;
		}
		else{
			low[node] = min(low[node], disc[it]);
		}
	}
	if(parent == -1 && child > 1){
		isAtri[node] = 1;
	}
}