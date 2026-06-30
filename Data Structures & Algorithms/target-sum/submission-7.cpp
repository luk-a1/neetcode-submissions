class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<int, int> m;

        m[0] = 1;
        
        for(int i=0;i<nums.size();i++){
            unordered_map<int, int> m2;
            for(auto a:m){
                m2[a.first+nums[i]] += m[a.first];
                m2[a.first-nums[i]] += m[a.first];
            }
            m = m2;
        }

        return m[target];
    }
};
