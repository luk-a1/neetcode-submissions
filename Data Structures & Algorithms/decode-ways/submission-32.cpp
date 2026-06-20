class Solution {
public:
    int dfs(int i, int n, string &s, vector<int>& dp){
        if(i > n-1) return 1;
        if(s[i] == '0') return 0;
        if(i == n-1){
            if(s[i] == '0'){ return 0;}
            else{ return 1;}
        }
        int sum1 = 0, sum2 = 0;
        
        if(i < n-1)
            if(s[i] == '1' || (s[i] == '2' && s[i+1]-'0' < 7))
                if(dp[i+2] == -1)
                    sum1 = dfs(i+2, n, s, dp);
                else sum1 = dp[i+2];
        
        if(dp[i+1] == -1) sum2 = dfs(i+1, n, s, dp);
        else sum2 = dp[i+1];

        dp[i] = sum1+sum2;
        return dp[i];
    }
    
    int numDecodings(string s) {
        vector<int> dp(101, -1);
        return dfs(0, s.length(), s, dp);
    }
};
