class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};
        vector<vector<int>> adj(n);

        for(auto& edge:edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> edge_cnt(n);
        queue<int> leaves;

        for(int i=0;i<n;i++){
            edge_cnt[i] = (int)adj[i].size();
            if(adj[i].size() == 1)
                leaves.push(i);
        }
        int cnt = n;
        while(!leaves.empty()){
            if(cnt <= 2){
                vector<int> output;
                while(leaves.size())
                    output.push_back(leaves.front()), leaves.pop();
                
                return output;
            }

            int size = leaves.size();

            for(int i=0;i<size;i++){
                int node = leaves.front();
                leaves.pop();
                --cnt;
                for(auto a:adj[node]){
                    edge_cnt[a]--;
                    if(edge_cnt[a] == 1)
                        leaves.push(a);
                }
            }
        }

        return {};
    }
};