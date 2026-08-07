class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k) return arr;

        int l = 0, r = k-1;

        while( r < arr.size()-1 ){
            if(abs(x - arr[l]) <= abs(x - arr[r+1]) && arr[l] != arr[r+1]){
                return vector<int>(arr.begin() + l, arr.begin() +l + k);
            }
            else{
                l+=1;
                r+=1;
            }
        }

        return vector<int>(arr.begin()+l, arr.begin()+k+l);

    }
};