class Solution {
public:

    bool detectCycle(int v, vector<vector<int>>& adj, vector<bool>& visited){
        visited[v] = true;
        bool out = true;

        for(auto a:adj[v])
            if(visited[a]) return false;
            else{
                visited[a] = true;
                out&= detectCycle(a, adj, visited);
                visited[a] = false;
            }
        
        return out;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<bool> visited(numCourses, false);

        for(auto a:prerequisites)
            adj[a[1]].push_back(a[0]);

        for(auto a:adj){
            for(auto b:a)
                cout<<b<<" ";
            cout<<"\n";
        }
        
        bool a = true;

        for(int i=0;i<numCourses;i++)
            if(!visited[i] && adj[i].size() > 0){
                a = a && detectCycle(i, adj, visited);
                visited.assign(numCourses, false);
            }
        
        return a;


    }
};
