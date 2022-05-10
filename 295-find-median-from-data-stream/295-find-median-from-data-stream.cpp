class MedianFinder {
    priority_queue<int> f;
    priority_queue<int, vector<int>, greater<int>> b;
public:
    void balance() {
        if (f.size() - b.size() == 2) {
            b.push(f.top());
            f.pop();
        }
        if (b.size() - f.size() == 1) {
            f.push(b.top());
            b.pop();
        }
    }
    
    void addNum(int num) {
        (f.empty() or num < f.top()) ? f.push(num) : b.push(num);
        balance();
    }
    
    double findMedian() {
        return (f.size() > b.size()) ? f.top() : (f.top() + b.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */