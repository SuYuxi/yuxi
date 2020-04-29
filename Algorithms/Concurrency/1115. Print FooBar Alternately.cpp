#include <condition_variable>
#include <mutex>

class FooBar {
private:
    int n;
    int state;
    std::mutex m;
    std::condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
        state = 0;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {            
        	// printFoo() outputs "foo". Do not change or remove this line.
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return state == 0;});
        	printFoo();
            state = 1;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {      
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lk(m);
            cv.wait(lk, [this]{return state == 1;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            state = 0;
            cv.notify_all();
        }
    }
};
