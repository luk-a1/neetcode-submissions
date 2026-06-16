class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> out(n+1, 0);
        for(int i=1;i<=n;i++){
            int k = i;
            while(k){
                out[i] += k&1;
                k = k>>1;
            }
            
        }
        return out;
    }
};
