#include <mutex>
#include <condition_variable>
#include <deque>

class BoundedBlockingQueue {
public:
    BoundedBlockingQueue(int capacity) {
        m_capacity = capacity;
    }
    
    void enqueue(int element) {
        std::unique_lock<std::mutex> lk(m);
        if(queue.size() >= m_capacity) cv.wait(lk, [this]{return queue.size() < m_capacity;});
        queue.emplace_back(element);
        lk.unlock();
        cv.notify_all();
    }
    
    int dequeue() {
        std::unique_lock<std::mutex> lk(m);
        if(queue.empty()) cv.wait(lk, [this]{return !queue.empty();});
        int val = queue.front();
        queue.pop_front();
        lk.unlock();
        cv.notify_all();
        return val;
    }
    
    int size() {
       return queue.size(); 
    }
    
private:
    int m_capacity;
    std::deque<int> queue;
    std::mutex m;
    std::condition_variable cv;
};
