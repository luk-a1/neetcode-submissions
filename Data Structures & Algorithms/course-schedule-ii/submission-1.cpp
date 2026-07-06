class Solution {
public:
    bool dfs(int x, vector<vector<int>>& adj, vector<int>& currinrow, set<int>& visited, set<int>& cycle){
        if(cycle.find(x) != cycle.end()) 
            return false;
        
        if(visited.find(x) != visited.end()) return true;
        
        cycle.insert(x);

        for(auto a:adj[x])
            if(dfs(a, adj, currinrow, visited, cycle) == false)
                return false;

        cycle.erase(x);
        visited.insert(x);
        currinrow.push_back(x);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);

        for(auto& a : prerequisites)
            adj[a[0]].push_back(a[1]);

        set<int> visited;
        vector<int> currinrow;
        set<int> cycle;

        bool t = true;
        
        for(int i=0;i<numCourses;i++)
            if(visited.find(i) == visited.end())
                t &= dfs(i, adj, currinrow, visited, cycle);
        if(t) return currinrow;
        return {};
    }
};
