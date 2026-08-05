class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            if(i > 0 && nums[i-1] == nums[i]) continue;

            for(int j = i+1; j < nums.size();j++){
                if(j > i+1 && nums[j] == nums[j-1]) continue;

                int l {j+1};
                int r = nums.size()-1;
                long long curr_sum = nums[i] + nums[j];

                while(l < nums.size() && r >= 0 && l < r){
                    if(nums[l] + nums[r] + curr_sum < target)
                    {
                        ++l;
                    } else 
                    {
                        if(nums[l] + nums[r] + curr_sum > target) --r;
                        else{
                            output.push_back({nums[i], nums[j], nums[l], nums[r]});
                            ++l;
                            --r;

                            while(l < nums.size() && nums[l-1] == nums[l]) ++l;
                            while( r >= j && nums[r+1] == nums[r]) --r;
                        }
                    }
                }

            }
        }
        return output;
    }

    //-3, 0, 1, 2, 3, 3
};