class Solution {
    vector<vector<int>> output;
public:
    void dfs( int i, vector<int> curr, vector<int>& nums){
        output.push_back(curr);

        for(int j=i;j<nums.size();j++)
        {
            if(j > i && nums[j] == nums[j-1])
                continue;

            curr.push_back(nums[j]);
            dfs(j+1, curr, nums);
            curr.pop_back();
        }

        
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        dfs(0, {}, nums);
        return output;
    }
};
