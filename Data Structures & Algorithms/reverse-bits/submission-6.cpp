class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t coe = 1<<31;
        for(int i=0;i<16;i++){
            uint32_t coe = (1<<(32-i-1));
            uint32_t left = ((n>>(31-i))&1);
            uint32_t right = (n>>i)&1;
            n &= ~(1<<(31-i));
            n &= ~(1<<i);
            n |= (right<<(31-i));
            n |= (left<<(i));
        }

        return n;
    }
};
