// This algorithm is used for finding strongly connected components in the graph.

#include<bits/stdc++.h>
using namespace std;


void topo(int node, stack<int> &st, vector<int> adj[], vector<int> &vis){
	vis[node] = 1;
	for(auto it: adj[node]){
		if(!vis[it]){
			topo(it, st, adj, vis);
		}
	}
	st.push(node);
}

void reversedfs(int node, vector<int>&vis, vector<int> transpose){
	vis[node] = 1;
	cout<<node<<" ";
	for(auto it: transpose[node]){
		if(!vis[it]){
			reversedfs(it, vis, transpose);
		}
	}
}


int main(){
	int N,m;
	cin>>N>>m;

	vector<int>adj[n];

	for(int i=0; i<m; i++){
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
	}

	stack<int> st;
	vector<int> vis(N, 0);
	for(int i=0; i<N; i++){
		if(!vis[i]){
			topo(i, st, adj, vis);
		}
	}

	vector<int> transpose[n];

	for(int i=0; i<n; i++){
		vis[i] = 0;
		for(auto it: adj[i]){
			transpose[it].push_back(i);
		}
	}

	while(!st.empty()){
		int node = st.top();
		st.pop();
		if(!vis[node]){
			reversedfs(node, vis, transpose)
		}
		cout<<endl;
	}

	return 0;
}