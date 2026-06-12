class Solution {
public:
    bool bfs(vector<vector<int>>& adj, vector<bool>& visited){
        int n = adj.size();
        
        vector<int> parent(n);
        queue<vector<int>> q;
        parent[0] = -1;
        q.push({0, -1});

        while(!q.empty()){
            int curr = q.front()[0];
            visited[curr] = true;
            int parent = q.front()[1];
            q.pop();
            for(auto a:adj[curr]){
                if(a == parent) continue;
                if(visited[a]) return false;
                q.push({a, curr});
            }
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        for(auto a:edges){
            int u = a[0];
            int v = a[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool out = bfs(adj, visited);

        for(auto a:visited)
            out &= a;

        return out;
    }
};
