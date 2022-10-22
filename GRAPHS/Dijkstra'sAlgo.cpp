#include<bits/stdc++.h>
using namespace std;

void Dijkstra(int n, int source, vector<pair<int, int> adj[]){

	priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	vector<int> dis(n, INT_MAX);

	dis[source] = 0;
	pq.push({0, source});

	while(!pq.empty()){
		int node = pq.top().second;
		int dist = pq.top().first;
		pq.pop();

		vector<pair<int, int>>::iterator it;

		for(it = adj[node].begin(); it != adj[node].end(); it++){
			if(dist+it->second < dis[it->first]){
				dis[it->first] = dist+it->second;
				pq.push({dis[it->first], it->first});
			}
		}
	}

	for(int i=0; i<n; i++){
		cout<<i<<"-:"<<dis[i]<<endl;
	}
}


int main(){

	int n, m, source;
	cin>>n>>m;

	vector<pair<int, int>>adj[n];
	int a, b, wt;

	for(int i=0; i<m; i++){
		cin>>a>>b>>wt;
		adj[a].puah_back({b,wt});
		adj[b].push_back({a, wt});
	}

	cin>>source;

	return 0;
}