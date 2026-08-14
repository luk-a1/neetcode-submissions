class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());
        if(visit.count("0000")) return -1;

        queue<pair<string, int>> q;
        q.push({
            "0000",
            0
        });

        visit.insert("0000");

        while(q.size()){
            auto [combination, turn] = q.front();
            q.pop();

            if(combination == target) return turn;

            for(int i=0;i<4;i++){
                int c = combination[i];
                combination[i] = (c - '0' + 1) %10 + '0';
                if(!visit.count(combination))
                    q.push({combination, turn+1}), visit.insert(combination);

                combination[i] = (c - '0' - 1 + 10) % 10 + '0';
                if(!visit.count(combination))
                    q.push({combination, turn+1}), visit.insert(combination);
                
                combination[i] = c;
            }
        }

        return -1;

    }
};