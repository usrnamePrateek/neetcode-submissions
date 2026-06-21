class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> subRes;
        sol(nums, 0, target, subRes);
        return res;
    }

    void sol(vector<int>& nums, int idx, int target, vector<int>& currRes) {
        if (target == 0) {
            res.push_back(currRes);
            return;
        }

        for (int i = idx; i < nums.size(); i++) {
            if (nums[i] <= target) {
                currRes.push_back(nums[i]);
                sol(nums, i, target - nums[i], currRes);
                currRes.pop_back();
            }
        }
    }
};
