class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1, 0);
        int n = s.size();
        if(n==0) return 0;

        dp[s.size()-1] = s[s.size()-1] == '0' ? 0:1;
        if(n == 1) return dp[n-1];
        
        if(s[n-2] == '1' || (s[n-2] == '2' && s[n-1]-'0' < 7)) dp[n-2] = 1+dp[n-1];
        else if(s[n-2] != '0') dp[n-2] = dp[n-1];
        else dp[n-2] = 0;
        
        int one_dig = 0, two_dig = 0;
        for(int i=n-3;i>=0;i--){
            if(s[i] == '1' || (s[i] == '2' && s[i+1]-'0'<7)) dp[i] = dp[i+1] + dp[i+2];
            else if(s[i] == '0') dp[i] = 0;
            else dp[i] = dp[i+1];
            cout<<i<<" "<<dp[i]<<"\n";
        }

        return dp[0];
    }
};
