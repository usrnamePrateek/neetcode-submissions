class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int a = i + 1;
            int b = nums.size() - 1;

            while (a < b) {
                if (nums[i] + nums[a] + nums[b] == 0) {
                    res.push_back({nums[i], nums[a], nums[b]});
                    a++;
                    while (a < nums.size() && nums[a - 1] == nums[a]) {
                        a++;
                    }

                    b--;
                    while (b >= 0 && nums[b + 1] == nums[b]) {
                        b--;
                    }
                } else if (nums[i] + nums[a] + nums[b] < 0) {
                    a++;
                } else {
                    b--;
                }
            }
        }

        return res;
    }
};
