class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        priority_queue<tuple<int, int, int>> q;

        vector<vector<vector<int>>> adj(n);
        vector<int> dist(n, 1e9);

        for(int i=0;i<flights.size();i++)
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});

        dist[src] = 0;
        q.push({0, src, 0});

        while(!q.empty()){
            auto [cost, curr, stop] = q.top();
            q.pop();
            
            if(stop > k) continue;

            for(auto a:adj[curr]){
                int c = a[1];
                int node = a[0];
                if(c + cost < dist[node]){
                    dist[node] = c+dist[curr];
                    q.push({dist[node], node, stop+1});
                }
            }


        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};
