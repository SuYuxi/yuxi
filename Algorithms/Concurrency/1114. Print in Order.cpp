#include <condition_variable>
#include <mutex>

class Foo {
public:
    Foo() {
        state = 0;
    }
    
    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lk(m);
        //when predict equals true, this thread does not block.
        cv.wait(lk, [this]{return state == 0;});
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        state = 1;
        lk.unlock();
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{return state == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        state = 2;
        lk.unlock();
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lk(m);
        cv.wait(lk, [this]{return state == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        state = 0;
        lk.unlock();
    }
private:
    std::mutex m;
    std::condition_variable cv;
    int state;
};

