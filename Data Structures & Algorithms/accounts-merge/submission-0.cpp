struct DSU{
    vector<int> parent;
    vector<int> rank;

    DSU(vector<vector<string>>& accounts){
        parent.resize(accounts.size());
        rank.resize(accounts.size());
        for(int i=0;i<accounts.size(); i++)
            parent[i] = i, rank[i] = 1;
    }

    int find_parent(int x){
        if(x == parent[x])
            return x;
        
        return parent[x] = find_parent(parent[x]);
    }

    void merge(int x, int y){
        x = find_parent(x);
        y = find_parent(y);
        if(x == y) return;
        if(rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        rank[x] += rank[y];
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> m;
        DSU dsu(accounts);

        for(int i=0; i<accounts.size(); i++)
            for(int j=1; j<accounts[i].size(); j++)
                if(!m.contains(accounts[i][j]))
                    m[accounts[i][j]] = i;
                else
                    dsu.merge(m[accounts[i][j]], i);
        
        map<int, vector<string>> emails;
        
        for(auto& [email, parent] : m)
            emails[dsu.find_parent(parent)].push_back(email);
        
        vector<vector<string>> output;

        for(auto& [accid, email] : emails){
            sort(email.begin(), email.end());
            vector<string> temp;
            temp.push_back(accounts[accid][0]);
            temp.insert(temp.end(), email.begin(), email.end());
            output.push_back(temp);
        }

        return output;
        
    }
};