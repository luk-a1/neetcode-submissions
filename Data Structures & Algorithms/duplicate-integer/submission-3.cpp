class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> m;

        for(auto a:nums)
            if(m.find(a) != m.end())
                return true;
            else m[a] = 1;
        return false;
    }
};