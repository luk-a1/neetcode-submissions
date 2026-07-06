class Solution {
private:
    vector<vector<int>> adj;
    vector<int> currinrow;
    set<int> visited;
    set<int> cycle;
public:
    bool dfs(int x){
        if(cycle.find(x) != cycle.end()) 
            return false;
        
        if(visited.find(x) != visited.end()) return true;
        
        cycle.insert(x);

        for(auto a:adj[x])
            if(dfs(a) == false)
                return false;

        cycle.erase(x);
        visited.insert(x);
        currinrow.push_back(x);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        adj = vector<vector<int>>(numCourses);

        for(auto& a : prerequisites)
            adj[a[0]].push_back(a[1]);

        bool t = true;
        
        for(int i=0;i<numCourses;i++)
            if(visited.find(i) == visited.end())
                t &= dfs(i);
        if(t) return currinrow;
        return {};
    }
};
