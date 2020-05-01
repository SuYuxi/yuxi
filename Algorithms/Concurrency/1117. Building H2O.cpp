#include <mutex>
#include <condition_variable>

class H2O {
public:
    H2O() {
        count = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock<std::mutex> lk(m);
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        cv.wait(lk, [this]{return count < 2;});
        count += 1;
        releaseHydrogen();
        lk.unlock();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{return count >= 0;});
        count -= 2;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        lk.unlock();
        cv.notify_all();
    }
    
private:
    std::mutex m;
    std::condition_variable cv;
    int count;
};
