class Solution {
public:
    void dfs(int x, vector<bool>& visited, vector<vector<int>>& adj, unordered_map<int, set<int>>& required){
        if(visited[x]) return;

        for(auto a:adj[x]){ 
            if(!visited[a]) 
                dfs(a, visited, adj, required);
            required[x].insert(required[a].begin(), required[a].end());
            required[x].insert(a);
        }
        
        visited[x] = true;
    }

    // [a, b] -> a is required for b
    vector<bool> checkIfPrerequisite(
        int numCourses,
        vector<vector<int>>& prerequisites, 
        vector<vector<int>>& queries
    ) {
                                    
        vector<vector<int>> adj(numCourses);
        unordered_map<int, set<int>> required;
        vector<bool> visited(numCourses, false);

        for(auto a:prerequisites){
            adj[a[1]].push_back(a[0]);
        }
        
        for(int i=0;i<numCourses;i++){
            if(visited[i] == false)
                dfs(i, visited, adj, required); 
        }
        vector<bool> output;

        for(int i=0;i<numCourses;i++){
            for(auto it:required[i]){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        for(auto a:queries){
            if(required[a[1]].find(a[0]) != required[a[1]].end())
                output.push_back(true);
            else output.push_back(false);
        }

        return output;
    }
};