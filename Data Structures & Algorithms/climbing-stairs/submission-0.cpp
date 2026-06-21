class Solution {
   public:
    unordered_map<int, int> mem;
    int climbStairs(int n) {
        if (mem.count(n)) {
            return mem[n];
        }

        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        mem[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return mem[n];
    }
};
