class Solution {
public:
    
    void backtrack(set<vector<int>>& out, int i, vector<int> curr, vector<int>& nums){
        out.insert(curr);
        if(i == nums.size()) return;
        backtrack(out, i+1, curr, nums);
        curr.push_back(nums[i]);
        backtrack(out, i+1, curr, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        set<vector<int>> out;
        vector<vector<int>> outt;
        vector<int> curr;

        backtrack(out, 0, curr, nums);
        for(auto a:out) outt.push_back(a);

        return outt;
    }
};
