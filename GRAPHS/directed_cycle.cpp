#include<bits/stdc++.h>
using namespace std;


bool check_cycle(int x, vector<int> adj[], vector<int>& vis, vector<int>& dfs_vis){
	vis[i] = 1;
	dfs_vis[i] = 1;
	for(auto it: adj[i]){
		if(!vis[it]){
			if(check_cycle(it, adj, vis, dfs_vis)){
				return true;
			}
		}
		else if (dfs_vis[it]){
			return true;
		}
	}
	dfs_vis[i] = 0;
	return false;
}

bool detect_cycle(int V, vector<int> adj[]){
	vector<int> vis(V, 0);

	vector<int> dfs_vis(V, 0);

	for(int i=0; i<V; i++){
		if(!vis[i]){
			if(check_cycle(i, adj, vis, dfs_vis)){
				return true;
			}
		}
	}
	return false;
}



int main(){


	return 0;
}