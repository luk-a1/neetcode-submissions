class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_cost = accumulate(cost.begin(), cost.end(), 0);
        int total_gas = accumulate(gas.begin(), gas.end(), 0);
        if(total_gas < total_cost) return -1;
        int curr = 0;
        int idx = 0;
        for(int i=0;i<gas.size();i++){
            curr += gas[i];
            curr -= cost[i];
            if(curr < 0){
                curr = 0;
                idx = i+1;
            } 
        }

        return idx;
    }
};
