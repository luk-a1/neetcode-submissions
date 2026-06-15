class Solution {
public:

    void dfs(int left, int right, int n, vector<string>& out, string curr){
        if(left == right && left == n) {out.push_back(curr); return;}
        if(left < n) dfs(left+1, right, n , out, curr+"(");
        if(left > right) dfs(left, right+1, n, out, curr+")");

    }
    vector<string> generateParenthesis(int n) {
        vector<string> out;
        string curr = "";

        dfs(0, 0, n, out, curr);
        return out;
    }
};
