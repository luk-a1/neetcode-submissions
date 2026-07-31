class Solution {
private:
    int check(vector<int>& weights, int size){
        int cnt=0;
        int curr=0;
        for(int i=0;i<weights.size();i++){
            if(curr + weights[i] == size){
                curr = 0;
                ++cnt;
            } else if(curr + weights[i] > size){
                curr = weights[i];
                ++cnt;
            }
            else{
                curr += weights[i];
            }
        }

        if(curr > 0) ++cnt;

        return cnt;

    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int r = accumulate(weights.begin(), weights.end(), 0);
        int l = *max_element(weights.begin(), weights.end());
        int output;
        while(l <= r){
            int mid = r - (r-l)/2;
            int curr = check(weights, mid);

            if(curr <= days){
                r = mid-1;
                output = mid;
            }
            else l = mid+1;
        }

        return output;

    }
};