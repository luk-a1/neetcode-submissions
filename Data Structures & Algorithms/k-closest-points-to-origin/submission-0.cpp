class Solution {
public:

    struct CMP{
        bool operator()(vector<int>& p1, vector<int>& p2){
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int> >, CMP> pq;

        for(auto a:points){
            if(pq.size() == k){
                pq.push(a);
                pq.pop();
            } 
            else pq.push(a);
        }
        vector<vector<int>> out;
        for(int i=0;i<k;i++){
            auto a = pq.top();
            pq.pop();
            out.push_back(a);
        }
        return out;
    }
};
