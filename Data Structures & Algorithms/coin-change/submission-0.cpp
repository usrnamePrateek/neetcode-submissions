class Solution {
   public:
    vector<vector<int>> mem;

    int coinChange(vector<int>& coins, int amount) {
        mem.resize(amount + 1, vector<int>(coins.size(), -1));
        int res = sol(coins, amount, 0);
        return res >= 1e9 ? -1 : res;
    }

    int sol(vector<int>& coins, int amount, int idx) {
        if (amount == 0) {
            return 0;
        }

        if (mem[amount][idx] != -1) {
            return mem[amount][idx];
        }

        int req = 1e9;
        for (int i = idx; i < coins.size(); i++) {
            if (amount < coins[i]) {
                break;
            }

            req = min(req, 1 + sol(coins, amount - coins[i], i));
        }

        mem[amount][idx] = req;
        return req;
    }
};
