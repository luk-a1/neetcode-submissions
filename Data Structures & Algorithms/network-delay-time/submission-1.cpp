class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<vector<int>>> adj(n+1);

        for(auto a:times)
            adj[a[0]].push_back({a[1], a[2]});
        


        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > q;
        q.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(!q.empty()){
            int distt = q.top()[0]; int curr = q.top()[1];
            q.pop();

            if(distt > dist[curr])
                continue;

            for(auto& a:adj[curr]){
                int v = a[0];
                int d = a[1];
                if(dist[curr] + d < dist[v]){
                    dist[v] = dist[curr] + d;
                    q.push({dist[v], v});
                }
            }
        }

        int output = 0;

        for(int i=1;i<n+1;i++){
            output = max(output, dist[i]);
            if(dist[i] == 1e9)
                return -1;
        }

        return output;

        
    }
};
