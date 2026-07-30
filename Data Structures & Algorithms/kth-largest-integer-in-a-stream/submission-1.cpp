class KthLargest {
private:
    vector<int> v;
    int k;
public:
    KthLargest(int k_, vector<int>& nums) {
        k = k_;
        v = nums;
    }
    
    int add(int val) {
        v.push_back(val);
        priority_queue<int> q;
        for(int i=0;i<v.size();i++){
            q.push(v[i]);
            if(i > v.size() - k) q.pop();
        }

        return q.top();
    }
};
