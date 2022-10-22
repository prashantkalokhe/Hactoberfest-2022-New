#include<bits/stdc++.h>
using namespace std;

void find_topo(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
	vis[node] = 1;
	for(auto it: adj[node]){
		if(!vis[it]){
			find_topo(it, adj, vis, st);
		}
	}
	st.push(node);
}

vector<int> topological(int V, vector<int> adj[]){
	vector<int> vis(V, 0);

	stack<int> st;

	for(int i=0; i<V; i++){
		if(!vis[i]){
			find_topo(i, adj, vis, st);
		}
	}
	vector<int> ans;

	while(!st.empty()){
		int x = st.top();
		st.pop();

		ans.push_back(x);
	}
	return ans;
}