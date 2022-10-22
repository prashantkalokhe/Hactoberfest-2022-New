#include <bits/stdc++.h>
using namespace std;

vector<int>Topo_Sort(int V, vector<int> adj[]){
	vector<int> topo;
	vector<int>indegree(V, 0);

	for(int i=0; i<V; i++){
		for(auto it: adj[i]){
			indegree[it]++;
		}
	}

	queue<int> qt;
	for(int i=0; i<V; i++){
		if(indegree[i] == 0){
			qt.push(i);
		}
	}

	while(!q.empty()){
		int node = q.front();
		q.pop();
		topo.push_back(node);

		for(auto it: adj[node]){
			indegree[it]--;
			if(indegree[it] == 0){
				qt.push(it);
			}
		}
	}

	return topo;
}




int main(){


	return 0;
}