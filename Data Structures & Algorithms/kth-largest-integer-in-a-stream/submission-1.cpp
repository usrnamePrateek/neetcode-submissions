class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k = -1;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int i = 0; i < min((int)nums.size(), k); i++) {
            pq.push(nums[i]);
        }

        for (int i = k; i < nums.size(); i++) {
            if (nums[i] > pq.top()) {
                pq.pop();
                pq.push(nums[i]);
            }
        }
    }

    int add(int val) {
        if(pq.size() < k){
            pq.push(val);
        }

        else if (val > pq.top()) {
            pq.pop();
            pq.push(val);
        }

        return pq.top();
    }
};
