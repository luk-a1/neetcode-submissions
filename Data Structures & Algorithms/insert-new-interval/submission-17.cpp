class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> out;
        for(int i=0;i<intervals.size();i++){
            
            if(newInterval[1] < intervals[i][0]) {out.push_back(newInterval); for(int j = i;j<intervals.size();j++) out.push_back(intervals[j]); return out;}
            else if(newInterval[0] > intervals[i][1]) out.push_back(intervals[i]);
            else{
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            }
        }
        out.push_back(newInterval);
        return out;
    }
};
