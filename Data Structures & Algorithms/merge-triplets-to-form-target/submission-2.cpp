class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool first = false, second = false, third = false;
        for(auto a:triplets){
            if(a[0] > target[0] || a[1] > target[1] || a[2] > target[2])
                continue;
            
            first |= (a[0] == target[0]);
            second |= (a[1] == target[1]);
            third|= (a[2] == target[2]);
        }

        return first && second && third;
    }
};
