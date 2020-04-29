#include <mutex>
#include <condition_variable>

class ZeroEvenOdd {
private:
    int n;
    int current;
    bool state;
    std::mutex m;
    std::condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->current = 1; 
        this->state = false;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while(current <= n)
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return !state;});
            if(current <= n) printNumber(0);
            state = true;
            lk.unlock();
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while(current <= n)
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return state && !(current & 1);});
            if(current <= n) printNumber(current);
            state = false;
            current += 1;
            lk.unlock();
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while(current <= n)
        {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return state && (current & 1);});
            if(current <= n) printNumber(current);
            state = false;
            current += 1;
            lk.unlock();
            cv.notify_all();
        }
    }
};
