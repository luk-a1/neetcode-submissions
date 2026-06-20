class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> output;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){ return a[0] < b[0];});
        output.push_back(intervals[0]);
        
        for(int i=0;i<intervals.size();i++){
            auto& last = output[output.size()-1];

            if(! (last[1] < intervals[i][0])){
                last[0] = min(last[0], intervals[i][0]);
                last[1] = max(last[1], intervals[i][1]);
            }
            else output.push_back(intervals[i]);
        }
        return output;
    }
};
