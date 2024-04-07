class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t dk = 0;
        for (int i = 0; i < 32; i++) {
            dk <<= 1;
            dk |= n & 1;
            n >>= 1;
        }
        return dk;
    }
};