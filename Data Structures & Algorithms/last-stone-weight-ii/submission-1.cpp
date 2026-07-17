class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = accumulate(stones.begin(), stones.end(), 0)/2;
        vector<int> dp(n+1, 0);

        for(auto a:stones){
            for(int i = n; i >= a; i--)
            {
                dp[i] = max(dp[i], dp[i-a] + a);
            }
        }

        return accumulate(stones.begin(), stones.end(), 0) - 2*dp[n];
    }
};