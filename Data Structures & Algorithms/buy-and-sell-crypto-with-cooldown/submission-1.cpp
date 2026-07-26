class Solution {
public:

    int dfs(bool empty, int indx, int sum, vector<int>& prices){
        if(indx >= prices.size()) return sum;
        int hold = dfs(empty, indx+1, sum, prices);
        if(empty)
            return max(dfs(false, indx+1, sum-prices[indx], prices), hold);
        else
            return max(dfs(true, indx+2, sum + prices[indx], prices), hold);
            
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,0));
        //if(prices.size() == 1) return 0;

        for(int i=prices.size()-1;i>=0;i--){
            for(int k = 1;k >= 0; k--){
                if(k)
                    dp[i][1] = max(dp[i+1][0] - prices[i], dp[i+1][1]);
                else{
                    int selltoday = prices[i];
                    if(i < (int)prices.size()-2) selltoday += dp[i+2][1];
                    int stalltoday = dp[i+1][0];
                    dp[i][0] = max(selltoday, stalltoday);
                }
            }
            cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";

        }

        return dp[0][1];
    }
};
