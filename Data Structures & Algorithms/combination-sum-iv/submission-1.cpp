class Solution {
    unordered_map<int, int> m;
public:
    int dfs(vector<int>& nums, int target){
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(m.contains(target)) return m[target];
        int cnt = 0;

        for(int i=0;i<nums.size();i++)
            cnt += dfs(nums, target-nums[i]);
        
        m[target] = cnt;
        return cnt;

    }
    int combinationSum4(vector<int>& nums, int target) {
        return dfs(nums, target);

    }
};