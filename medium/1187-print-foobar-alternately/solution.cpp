#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class FooBar {
private:
    int n;
    mutex mtx;
    condition_variable cv;
    bool foo_turn;

public:
    FooBar(int n) {
        this->n = n;
        this->foo_turn = true; 
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);

            cv.wait(lock, [this]() { return foo_turn == true; });

            printFoo();

            foo_turn = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return foo_turn == false; });

            printBar();
            foo_turn = true;
            cv.notify_one();
        }
    }
};