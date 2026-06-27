class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;

        while( l <= r ){
            int mid = r - (r - l)/2;

            if(nums[mid] == target) return mid;

            if(nums[mid] <= nums[r]) // u desnom smo
            {
                if(nums[mid] < target)
                    if(target <= nums[r]) l = mid+1;
                    else r = mid-1;
                else
                    r = mid-1;
            }

            else{
                if(nums[mid] < target) l = mid+1;
                else{
                    if(target < nums[l]) l = mid+1;
                    else r = mid-1;
                }
            }

        }

        return -1;
    }
};
