class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int curr = 0;
        for(int i = digits.size()-1; i >= 0; i--){
            curr = (digits[i] + carry)%10;
            carry = (digits[i] + carry)/10;
            digits[i] = curr;
        }
        vector<int> out;
        if(!carry) return digits;
        else{
            out.push_back(carry);
            out.insert(out.begin()+1, digits.begin(), digits.end());
        }
        return out;
    }
};
