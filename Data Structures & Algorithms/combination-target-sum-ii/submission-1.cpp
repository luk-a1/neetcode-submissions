class Solution {
public:

    void dfs(int idx, vector<int> curr, vector<vector<int>>& output, vector<int>& nums, int target){
        if(accumulate(curr.begin(), curr.end(), 0) == target) {output.push_back(curr); return;}
        if(accumulate(curr.begin(), curr.end(), 0) > target) return;
        
        if(idx > nums.size()-1) return;
        for(int i = idx; i < nums.size(); i++){
            if(i > idx && nums[i] == nums[i-1]) continue;
            if(nums[i] > target) continue;

            curr.push_back(nums[i]);
            dfs(i+1, curr, output, nums, target);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        sort(candidates.begin(), candidates.end());
        dfs(0, vector<int>(), output, candidates, target);
        return output;

    }
};
