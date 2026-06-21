class MedianFinder {
   public:
    priority_queue<int, vector<int>, greater<int>> right;
    priority_queue<int, vector<int>> left;

    MedianFinder() {}

    void addNum(int num) {
        if(right.size() == 0){
            right.push(num);
            return;
        }

        if (left.size() == right.size()) {
            if (left.top() > num) {
                int leftmax = left.top();
                left.pop();

                right.push(leftmax);
                left.push(num);
            } else {
                right.push(num);
            }
        } else {
            if (right.top() < num) {
                int rightmin = right.top();
                right.pop();

                right.push(num);
                left.push(rightmin);
            } else {
                left.push(num);
            }
        }
    }

    double findMedian() {
        // cout << (left.empty() ? -1 : left.top()) << " " << right.top() << endl;
        if(left.size() == right.size()){
            return (left.top() + right.top()) / 2.0;
        }

        return right.top();
    }
};
