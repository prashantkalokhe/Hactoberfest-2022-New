

{
	public:
	//Function to return list containing vertices in Topological order. 
	void findtoposort(int node,vector<int>& vis,stack<int> &s,vector<int> adj[]){
          vis[node]=1;
          for(auto it:adj[node]){
              if(!vis[it]){
                  findtoposort(it,vis,s,adj);
              }
          }
          s.push(node);
	}
	
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            findtoposort(i,vis,s,adj);
	        }
	    }
	    vector<int> ans;
	    while(!s.empty()){
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	    
	}
};
