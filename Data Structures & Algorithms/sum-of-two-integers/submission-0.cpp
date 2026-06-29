class Solution {
   public:
    int getSum(int a, int b) {
        int c = 0;
        int sum = 0;

        for (int i = 0; i < 32; i++) {
            int abit = a & 1;
            int bbit = b & 1;
            sum += (abit ^ bbit ^ c) << i;
            c = (abit & bbit) | (bbit & c) | (c & abit);
            a >>= 1;
            b >>= 1;
        }

        return sum;
    }
};
