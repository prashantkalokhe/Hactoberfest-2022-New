#include<bits/stdc++.h>
using namespace std;


void MinimumSpanning(int V, vector<int> adj[], int parent[], int key[], int mstSet[]){
	for(int count=0; count<N-1, count++){
		int u = pq.top().second;
		pq.pop();

		
		mstSet[u] = true;

		for(auto it: adj[u]){
			int v = it.first;
			int weight = it.second;
			if(mstSet[v] == false && weight < key[v]){
				parent[v] = u;
				pq.push({key[v], v});
				key[v] = weight;
			}
		}
	}
}


int main(){

	int N, m;
	cin>>N>>m;

	vector<pair<int, int>> adj[N];
	int a,b,wt;
	for(int i=0; i<m; i++){
		cin>>a>>b>>wt;
		adj[a].push_back(b, wt);
		adj[b].push_back(a, wt);
	}

	int parent[N];
	int key[N];
	bool mstSet[N];

	for(int i=0; i<N; i++){
		parent[i] = -1;
		key[i] = INT_MAX;
		mstSet[i] = false;
	}
	key[0] = 0;
	parent[0] = -1;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
	pq.push({0,0});



	return 0;
}