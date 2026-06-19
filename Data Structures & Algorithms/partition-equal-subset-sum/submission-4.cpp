class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto a:nums) sum+=a;
        if(sum%2) return false;
        sum/=2;

        vector<bool> dp(sum+1, false);

        dp[0] = true;

        for(int i=0;i<nums.size();i++)
            for(int j=sum;j>=nums[i];j--)
                dp[j] = dp[j-nums[i]] || dp[j];
        
        return dp[sum];



    }
};
