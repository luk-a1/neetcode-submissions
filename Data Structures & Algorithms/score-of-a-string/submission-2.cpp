class Solution {
public:
    int scoreOfString(string s) {
        int cnt = 0;
        int n = s.size(); int i = 1;
        while( i < n )
            cnt += abs(s[i] - s[i++-1]);
        return cnt;
    }
};