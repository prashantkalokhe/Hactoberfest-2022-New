#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[]){
	vector<int> col(V+1, -1);

	for(int i=1; i<=V; i++){
		if(col[i] == -1){
			queue<pair<int, int>> qt;
			qt.push({i, 0});

			while(!qt.empty()){
				int node = qt.front().first;
				int colr = qt.front().second;
				qt.pop();

				for(auto it : adj[node]){
					if(col[it] == -1){
						if(colr == 0){
							q.push({it, 1});
							col[it] = 1;
						}
						if(colr == 1){
							q.push({it, 0});
							col[it] = 0;
						}
					}
					if(col[it] == colr){
						return false;
					}
				}

			}
		}
	}
	return true;
	
}