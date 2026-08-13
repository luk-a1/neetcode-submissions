class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<string> s;

        for(auto a:logs)
        {
            if(a == "../"){
                if(s.empty() == false){
                    s.pop();
                }
                continue;
            }
            if(a == "./"){
                continue;
            }
            s.push(a);
        }

        return s.size();
    }
};