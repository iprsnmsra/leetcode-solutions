#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class Foo {
private:
    std::mutex mtx;
    std::condition_variable cv;
    int state;

public:
    Foo() {
        state = 1;
    }

    void first(function<void()> printFirst) {
        std::unique_lock<std::mutex> lock(mtx);

        printFirst();

        state = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return state == 2; });

        printSecond();
        state = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [this]() { return state == 3; });
        printThird();
    }
};