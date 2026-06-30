class Solution {
public:
    void dfs(int indx, vector<int> curr, vector<vector<int>>& output, vector<int>& nums){
        if(indx == nums.size()) {output.push_back(curr); return;}
        int num = nums[indx];

        for(int i=0;i<curr.size()+1;i++){
            curr.insert(curr.begin()+i, num);
            dfs(indx+1, curr, output, nums);
            curr.erase(curr.begin()+i);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        dfs(0, vector<int>(), output, nums);
        return output;
    }
};
