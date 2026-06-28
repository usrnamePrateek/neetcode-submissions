class Solution {
   public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];
        int count = 0;

        for (int i = 1; i < intervals.size(); i++) {
            int currStart = intervals[i][0];
            int currEnd = intervals[i][1];

            if(currStart < end || currEnd < end){
                count++;
                end = min(currEnd, end);
            }else{
                start = currStart;
                end = currEnd;
            }
        }

        return count;
    }
};
