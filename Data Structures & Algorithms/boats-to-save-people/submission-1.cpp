class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> ccounter(*max_element(people.begin(), people.end())+1, 0);

        for(int i=0;i<people.size();i++)
            ccounter[people[i]]++;
        
        int j=0;
        for(int i=0;i<ccounter.size();i++){
            if(ccounter[i] == 0) continue;
            while(ccounter[i]){
                people[j++] = i;
                --ccounter[i];
            }
        }

        int l = 0;
        int r = people.size()-1;
        int cnt = 0;
        while(l<=r){
            if(people[r] == limit || people[r] + people[l] > limit){
                r--;
                cnt++;
                continue;
            }

            if(people[r] + people[l] <= limit ){
                cnt++;
                r--;
                l++;
                continue;
            }

        }

        return cnt;
        

    }
};