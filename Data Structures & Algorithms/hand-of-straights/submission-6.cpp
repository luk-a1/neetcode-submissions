class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize) return false;
        unordered_map<int, int> counter;

        for(auto a:hand)
            counter[a]++;

        for(auto& a:counter){
            int start = a.first;
            while(counter.contains(start-1)) {start--;}
            while(start <= a.first){
                while(counter[start])
                    for(int j=0;j<groupSize;j++){
                        if(!counter[start+j]){cout<<a.first<<" "<<start<<" "; return false;}
                        counter[start+j]--;
                    }
                start++;
            }
        }

        return true;

    }
};