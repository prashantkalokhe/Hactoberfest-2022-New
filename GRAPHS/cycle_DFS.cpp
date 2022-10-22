#include<bits/stdc++.h>
using namespace std;

bool isCycle(int x, vector<int>& vis, vector<int> adj[]){
	stack<pair<int, int>st;
	vis[x] = 1;
	st.push({x, -1});

	while(!st.empty()){
		int node = st.top().first;
		int par = st.top().second;
		st.pop();

		for(int j=0; j < adj[node].size(); j++){
			if(!vis[adj[node][j]]){
				vis[adj[node][j]] = 1;
				st.push({adj[node][j], node});
			}

			else if(vis[adj[node][j]] != par){
				return true;
			}
		}

	}
	return false;
}



bool Cycle(int V, vector<int> adj[]){
	vector<int> vis(V+1, 0);

	for(int i=1; i<=V; i++){
		if(!vis[i]){
			if(isCycle(i, vis, adj)){
				return true;
			}
		}
	}
	return false;
}


int main(){

	return 0;
}