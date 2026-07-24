class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> score;

        for(auto a:operations){
            if(a == "D")score.push(score.top()*2);
            else if(a == "C") score.pop();
            else if(a == "+"){
                int ttop = score.top();
                score.pop();
                int newtop = score.top();
                score.push(ttop);
                score.push(newtop + ttop);
            } else score.push(stoi(a));
        }

        int cnt = 0;

        while(!score.empty()){
            cnt+=score.top();
            score.pop();
        }

        return cnt;
    }
};