#include<bits/stdc++.h>
using namespace std;


bool isBipartite(vector<int> &col, int node, vector<int> adj[]){
	if(col[node] == -1) col[node] = 1;

	for(auto it: adj[node]){
		if(col[it] == -1){
			col[it] = 1 - col[node];
			if(!isBipartite(col, it, adj)){
				return false;
			}

			else if(col[it] == col[node]){
				return false;
			}
		}
	}
	return true;
}

bool ishelper(int V, vector<int> adj){
	vector<int> col(V, -1);

	for(int i=0; i<V; i++){
		if(col[i] == -1){
			if(!isBipartite(col, node, adj)){
				return false;
			}
		}
	}
	return true;
}