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
        int cnt=0;
        vector<int> start_times(intervals.size());
        vector<int> end_times(intervals.size());
        
        for(int i=0;i<intervals.size();i++){
            start_times[i] = intervals[i].start;
            end_times[i] = intervals[i].end;
        }
        if(start_times.size() == 0 || start_times.size()==1) return start_times.size(); 
        
        sort(start_times.begin(), start_times.end());
        sort(end_times.begin(), end_times.end());
        int n = intervals.size();
        int i = 0, j = 0;
        int cstart, cend;
        int maxx = 0;
        while(i < n){
            cstart = i >= n ? start_times[n-1] : start_times[i];
            cend = j >= n ? end_times[n-1] : end_times[j];

            if(cstart == cend){
                i++;
                j++;
            }
            if(cstart < cend){
                i++;
                cnt++;
                maxx = max(cnt, maxx);
            }
            if(cend < cstart){
                j++;
                cnt--;
            }

        }
        
        return maxx;        
    }
};
