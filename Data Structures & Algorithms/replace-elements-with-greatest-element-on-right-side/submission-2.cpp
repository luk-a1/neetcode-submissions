class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curr = -1;
        int i = arr.size()-1;
        while(i >= 0){
            int temp = arr[i];
            arr[i] = curr;
            curr = max(curr, temp);
            --i;
        }

        return arr;
    }
};