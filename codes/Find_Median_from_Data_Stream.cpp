class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
            while (maxHeap.size() - minHeap.size() > 1) {
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
            }
        } else {
            minHeap.push(num);
            while (minHeap.size() > maxHeap.size()) {
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
            }
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            return (double)(minHeap.top() + maxHeap.top()) / 2;
        } else {
            return (double)maxHeap.top();
        }
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
