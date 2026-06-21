class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> fIdx;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (fIdx.count(rem) != 0) {
                return {fIdx[rem], i};
            }

            if (fIdx.count(nums[i]) == 0) {
                fIdx[nums[i]] = i;
            }
        }

        return {};
    }
};
