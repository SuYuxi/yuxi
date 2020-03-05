class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        lo.emplace(num);
        hi.emplace(lo.top());
        lo.pop();
        
        if(lo.size() < hi.size())
        {
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian()
    {
        return lo.size() > hi.size() ? (double)lo.top() : 0.5 * (lo.top() + hi.top());
    }
private:
    priority_queue<int> lo;
    priority_queue<int, vector<int>, greater<int>> hi;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
