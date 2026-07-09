class Solution {

    bool is_in_set(int k, set<int>& ss){
        return ss.find(k) != ss.end();
    }

public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        set<int> ss;
        if(nums.size() == 1) return false;
        ++k;
        for(int i=0;i<nums.size();i++)
        {
            if( i < k ){
                ss.insert(nums[i]);
                continue;
            }

            if(ss.size() != k){
                return true;
            }
            else
            {
                ss.erase(nums[i-k]);
                ss.insert(nums[i]);
            }
        }
        cout<<ss.size() <<" " <<k;
        return (ss.size() != k);

    }
};