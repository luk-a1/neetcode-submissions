class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sol = nums[0];
        int curmax = 1; int curmin = 1;
        for(int i=0;i<nums.size();i++){
            int temp = curmax;
            curmax = max(max(curmin*nums[i], curmax*nums[i]), nums[i]);
            curmin = min(min(curmin*nums[i], temp*nums[i]), nums[i]);
            sol = max(sol, curmax);
        }

        return sol;
    }
};
