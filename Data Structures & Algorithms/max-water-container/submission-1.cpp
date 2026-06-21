class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int a = 0;
        int b = heights.size() - 1;

        int maxAr = 0;
        while (a < b) {
            maxAr = max(maxAr, min(heights[a], heights[b]) * (b - a));

            if (heights[a] > heights[b]) {
                b--;
            } else if (heights[a] < heights[b]) {
                a++;
            } else {
                a++;
                b--;
            }
        }

        return maxAr;
    }
};
