class MedianFinder {
    priority_queue<int> left;      // max heap
    priority_queue<int, vector<int>, greater<int>> right;      // min heap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(right.empty()) 
            left.push(num);
        else
        {
            if(num > right.top())
                right.push(num);
            else
                left.push(num);
        }

        // balance the both heaps

        int diff = left.size() - right.size();

        if(abs(diff) > 1)
        {
            if(left.size() > right.size())
            {
                right.push(left.top());
                left.pop();
            }
            else
            {
                left.push(right.top());
                right.pop();
            }
        }
    }
    
    double findMedian() {
        if(left.size() > right.size())
            return left.top();
        else if(left.size() < right.size())
            return right.top();
        
        return (right.top() + left.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */