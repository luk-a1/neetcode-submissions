class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> m;

        for(int i=0;i<s.size();i++)
            m[s[i]] = i;

        int i {0};
        int curr = m[s[0]];
        vector<int> output;

        while(i < s.size()){
            curr = m[s[i]];
            int start = i;
            while( i < curr ){
                i++;
                curr = max(curr, m[s[i]]);
            }
            output.push_back(curr+1 - start);
            i++;
        }
        return output;
    }
};
