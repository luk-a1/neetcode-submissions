class Solution {
public:

    void dfs(int i, int n, set<int>& pos, set<int>& neg, set<int>& row, set<int>& col, vector<string> curr, vector<vector<string>>& output){
        if(i == n) output.push_back(curr);
        
        string s = "";
        

        for(int k=0;k<n;k++){
            if(pos.find(k+i) != pos.end() || row.find(i) != row.end() || neg.find(k-i) != neg.end() || col.find(k) != col.end())
                continue;
            for(int j=0; j<k; j++) s+=".";
            s+="Q";
            for(int j = k+1; j<n; j++) s+=".";
            curr.push_back(s);
            neg.insert(k-i);
            pos.insert(k+i);
            row.insert(i);
            col.insert(k);
            dfs(i+1, n, pos, neg, row, col, curr, output);
            neg.erase(k-i);
            pos.erase(k+i);
            row.erase(i);
            col.erase(k);
            curr.erase(curr.end()-1);
            s = "";
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> output;
        vector<string> placement;
        set<int> pos;
        set<int> neg;
        set<int> row;
        set<int> col;
        
        dfs(0, n, pos, neg, row, col, placement, output);
        

        return output;
    }
};
