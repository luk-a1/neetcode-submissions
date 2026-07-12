class Solution {
public:
    int scoreOfString(string s) {
        int cnt = 0;
        int n = s.size();
        for(int i=1;i<n;i++)
            cnt += abs(s[i] - s[i-1]);
        return cnt;
    }
};