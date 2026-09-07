class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<pair<int, int>>> adj(n*n);
        
        vector<pair<int, int>> direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        for(auto i{0};i<grid.size();++i){
            for(auto j{0};j<grid[i].size();++j){
                for(auto d:direction){
                    if( i+d.first < 0 || 
                        i+d.first > grid.size()-1 ||
                        j+d.second < 0 || 
                        j+d.second > grid.size()-1)
                        continue;
                    
                    adj[i*n + j].push_back({(i+d.first)*n + j+d.second, max(grid[i][j], grid[i+d.first][j+d.second])});
                }
            }
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, 0});
        vector<int> dist(n*n, 1e9);

        dist[0] = 0;

        while(!q.empty()){
            auto [d, v] = q.top();
            q.pop();
            
            if(dist[v] < d) continue;

            for(auto a:adj[v]){
                auto [u, cost] = a;
                if(max(cost, dist[v]) < dist[u]){
                    dist[u] = max(cost, dist[v]);
                    q.push({dist[u], u});
                }
            }
        }
        return dist[n*n-1];
    }
};
