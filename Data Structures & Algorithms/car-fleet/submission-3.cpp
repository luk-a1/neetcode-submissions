class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v(position.size());
        
        for(int i=0;i<position.size();i++)
            v[i]={position[i], speed[i]};
        
        sort(v.begin(), v.end());
        int n = position.size();
        int cnt=0;
        float currtime = -1;
        for(int i=n-1;i>=0;i--){
            float time = float(target-v[i].first)/v[i].second;
            cout<<time<<"\n";
            if(time > currtime){
                cnt++;
                currtime = time;
            }
        }
        return cnt;

    }
};
