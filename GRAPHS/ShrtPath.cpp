#include<bits/stdc++.h>
using namespace std;

void BFS(int V, vector<int> adj[], int src){
	vector<int> dist(V, INT_MAX);
	queue<int> q;

	dist[src] = 0;
	q.push(src);

	while(q.empty()){
		int node = q.front();
		q.pop();

		for(auto it: adj[node]){
			if(dist[node] + 1 < dist[it]){
				dist[it] = dist[node]+1;
				q.push(it);
			}
		}
	}

	for(int i=0; i<V; i++){
		cout<<i<<" -: "<<dist[i]<<endl;
	}
}