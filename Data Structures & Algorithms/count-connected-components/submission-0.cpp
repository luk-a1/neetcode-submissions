class Solution {
public:
    void dfs(int v, vector<vector<int>>& adj, vector<bool>& visited){
        visited[v] = true;
        
        for(auto u:adj[v])
            if(!visited[u])
                dfs(u, adj, visited);
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);

        for(auto a:edges){
            int v = a[0];
            int u = a[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                cnt++;
            }
        }
        return cnt;
    }
};
