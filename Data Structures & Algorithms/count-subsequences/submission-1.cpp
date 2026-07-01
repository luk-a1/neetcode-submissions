class Solution {
public:

    int dfs(int idx_s, int idx_t, string& s, string& t){
        if(idx_t == t.size()) return 1;
        if(idx_s == s.size()) return 0;
        int t1 = dfs(idx_s+1, idx_t, s, t);
        if(s[idx_s] == t[idx_t]) return dfs(idx_s+1, idx_t+1, s, t) + t1;
        return t1;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size(), vector<int>(s.size(), 0));
        dp[0][0] = (s[0] == t[0]);

        for(int i=1;i<s.size();i++) dp[0][i] = (s[i] == t[0]) + dp[0][i-1];

        for(int i=1;i<t.size();i++){
            for(int j=i;j<s.size();j++){
                //if(i>0) dp[i][j] = dp[i-1][j-1];
                if(s[j]==t[i]) dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                else dp[i][j] = dp[i][j-1];
            }
        }
        return dp[t.size()-1][s.size()-1];
    }
};
