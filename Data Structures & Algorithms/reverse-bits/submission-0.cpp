class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        int ans = 0;
        for (int i = 1; i <= 32; i++) {
            int bit = (n & 1);
            ans += (bit << (32 - i));
            n >>= 1;
        }

        return ans;
    }
};
