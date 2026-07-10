class Solution {
public:

    struct DSU{


        DSU(int n) : size(vector<int>(n, 1)), parent(vector<int>(n)){ for(int i=0;i<n;i++) parent[i] = i;}

        int find_set(int v){
            if(v == parent[v])
                return v;
            return parent[v] = find_set(parent[v]);
        }

        bool unite(int a, int b){
            a = find_set(a);
            b = find_set(b);
            if(a == b)
                return true;
            
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];

            return false;
        }

        vector<int> size;
        vector<int> parent;
        
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(edges.size()+1);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int x = edges[i][1];

            if(dsu.unite(u, x))
                return edges[i];
        }
    }
};
