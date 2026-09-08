/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start_;
        vector<int> end_;
        int n = intervals.size();
        int i=0;
        int j = 0;
        for(auto a:intervals){
            start_.push_back(a.start);
            end_.push_back(a.end);
        }

        sort(start_.begin(), start_.end());
        sort(end_.begin(), end_.end());
        int cnt = 0; int maxx = 0;
        while(i < n && j < n){
            if(start_[i] < end_[j]){
                i++;
                cnt++;
            }
            else{
                ++j;
                cnt--;
            }
            maxx = max(maxx, cnt);
        }

        return maxx;
    }
};
