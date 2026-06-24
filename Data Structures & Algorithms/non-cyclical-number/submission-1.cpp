class Solution {
public:
    int digsum(int n){
        int cnt = 0;
        
        while(n){
            cnt += (n%10)*(n%10);
            n /= 10;
        }
        return cnt;
    }
    bool isHappy(int n) {
        unordered_set<int> s;
        int k = n;
        while(k != 1){
            k = digsum(k);
            if(s.find(k) != s.end()) return false;
            s.insert(k);
        }
        return true;
    }
};
