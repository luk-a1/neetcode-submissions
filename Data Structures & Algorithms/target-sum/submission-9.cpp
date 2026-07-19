class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((target + sum) % 2) return 0;
        vector<int> cnt((sum + target)/2+1); 
        cnt[0] = 1;
        for(auto a:nums){
            for(int t = (sum+target)/2; t>=a; --t){
                cnt[t] += cnt[t - a];
            }
        }

        return cnt[(sum+target)/2];
    }
};
