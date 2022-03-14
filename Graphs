#Graphs
// ask for self edges/self loops, parallel edges, directed/undirected, weighted/unweighted, connected/disconnected


// Cycle in undirected graph -- BFS

    bool bfsCycleCheck(int i, int V, vector<int> adj[], vector<bool> &vis){
        queue<pair<int, int>> q;
        vis[i] = true;
        q.push({i,-1});
        
        while(!q.empty()){
            auto f = q.front(); q.pop();
            int node = f.first, par = f.second; // [node, par]
            for(auto nbr: adj[node]){
                if(nbr == par) continue;
                if(vis[nbr]) return true;
                vis[nbr] = true;
                q.push({nbr, node});
            }
        }
        return false;
    }
    
    // dont forget to add parent as argument in dfsCycleCheck
      bool dfsCycleCheck(int i, int par, int V, vector<int> adj[], vector<bool> &vis){
        if(vis[i]) return true;
        vis[i] = true;
        for(auto nbr: adj[i]){
            if(nbr == par) continue;
            if(dfsCycleCheck(nbr, i, V, adj, vis)) return true;
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V, false);
        for(int i = 0; i<V; i++){
            if(vis[i]) continue;
            if(bfsCycleCheck(i,V,adj,vis)) return true; // little change in dfs call -- 1 argument extra
        }
        return false;
    }
    
    // Bipartite check
    
        bool bfsBipartite(int i, vector<vector<int>>& v, vector<int> &col){
        col[i] = 0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int node = q.front(); q.pop();
            
            for(auto nbr: v[node]){
                
                if(col[nbr] == -1){
                    col[nbr] = 1-col[node];
                    q.push(nbr);
                } 
                else if(col[nbr] == col[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    // added colour c as argument
      bool dfsBipartite(int i, int c, vector<vector<int>>& v, vector<int> &col){
        col[i] = c;
        for(auto nbr: v[i]){
            if(col[nbr] == -1){
                if(!dfsBipartite(nbr, 1-c, v, col)) return false;
            } else if (col[nbr] == col[i]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& v) {
        int n = v.size();
        vector<int> col(n, -1);
        
        for(int i=0; i<n; i++){
            
            if(col[i] != -1) continue;
            if(!bfsBipartite(i,v,col)) return false;
        }
        return true;
    }
    
    // Topological Sort 
    
    // using BFS
        bool canFinish(int n, vector<vector<int>>& edge) {
        map <int, vector<int>> mp;
        vector<int> indeg(n,0);
        for (auto &it: edge) {
            mp[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        vector<int> vis(n, false);
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
                vis[i] = true;
            }
        }
        while(!q.empty()){
            int f = q.front(); q.pop();
            for(int nbr: mp[f]){
                indeg[nbr]--;
                if(indeg[nbr] == 0){
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
        for(int i = 0; i<n; i++)
            if(!vis[i]) return false;
        return true;
    }
    
    // Using DFS
    
        void dfsTopoSort(int i, map <int, vector<int>> &mp, vector<int> &indeg, vector<int> &vis){
        for(int nbr: mp[i]){
            indeg[nbr]--;
            if(indeg[nbr] == 0){
                vis[nbr] = true;
                dfsTopoSort(nbr, mp, indeg, vis);
            }
        }
    }
    
    bool canFinish(int n, vector<vector<int>>& edge) {
        map <int, vector<int>> mp;
        vector<int> indeg(n,0);
        for (auto &it: edge) {
            mp[it[0]].push_back(it[1]);
            indeg[it[1]]++;
        }
        
        vector<int> vis(n, false);
        
        for(int i = 0; i<n; i++){
            if(indeg[i] == 0){
                vis[i] = true;
                dfsTopoSort(i, mp, indeg, vis);
            } 
        }
        
        for(int i = 0; i<n; i++)
            if(!vis[i]) return false;
        return true;
    }
    
    //
