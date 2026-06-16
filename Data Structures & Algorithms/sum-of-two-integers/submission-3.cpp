class Solution {
public:
    int getSum(int a, int b) {
        uint32_t carry=0;
        uint32_t curr;
        int out = 0;
        int i=0;
        for(int i=0;i<32;i++){
            uint32_t b1 = a&1;
            uint32_t b2 = b&1;
            curr = b1 ^ b2 ^ carry;
            carry = (b1 & b2) || (carry & (b1^b2));
            out |= (curr<<i);
            a>>=1;
            b>>=1;
        }
        return out;
    }
};
