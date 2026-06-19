class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[n] = true;
        
        for(int i=n-1;i>=0;i--){
            for(auto &a : wordDict){
                if(n-i >= a.size() && (s.substr(i, a.size()) == a)) 
                    dp[i] = dp[i+a.size()];

                if(dp[i]) break;
            }
        }

        for(auto a:dp) cout<<a<<" ";
        return dp[0];
    }
};
