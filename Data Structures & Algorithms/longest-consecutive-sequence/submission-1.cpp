class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        int maxSize = 0;

        for (int& num : nums) {
            numSet.insert(num);
        }

        for (int& num : nums) {
            int temp = num;

            if (numSet.count(temp - 1) != 0) {
               continue;
            }

            int size = 1;
            while (numSet.count(temp + 1) != 0) {
                temp++;
                size++;
            }

            maxSize = max(maxSize, size);
        }

        return maxSize;
    }
};
