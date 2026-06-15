class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> m1;
        m1[0] = 1;

        for(int i=0;i<nums.size();i++){
            unordered_map<int, int> m2;
            for(auto a:m1){
                m2[a.first + nums[i]] += a.second;
                m2[a.first - nums[i]] += a.second;
            }
            m1 = m2;
        }

        return m1[target];



    }
};
