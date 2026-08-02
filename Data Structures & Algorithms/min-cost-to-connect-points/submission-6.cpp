vector<int> parent, r;

void makeset(int v){
    parent[v] = v;
    r[v] = 1;
}

int find_parent(int v){
    if(parent[v] == v) return v; 
    return parent[v] = find_parent(parent[v]);

}

void merge(int v, int u){
    v = find_parent(v);
    u = find_parent(u);
    if(r[v] < r[u]) swap(v, u); // uvek se pridruzuje u v

    parent[u] = v;
    r[v] += r[u];
}

struct Edge{
    int x, u, weight;
    bool operator<(Edge const& o){
        return weight < o.weight;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<Edge> v;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                v.push_back(Edge(i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])));
            }
        }

        r.resize(points.size());
        parent.resize(points.size());

        for(int i=0;i<points.size();i++){
            makeset(i);
        }

        sort(v.begin(), v.end());
        int cost = 0;

        for(auto e:v){
            if(find_parent(e.x) != find_parent(e.u)){
                merge(e.x, e.u);
                cost += e.weight;
            }
        }

        return cost;
    }
};
