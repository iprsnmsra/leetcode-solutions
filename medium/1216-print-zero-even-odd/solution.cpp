#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int i;
    int turn; 
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->i = 1;   
        this->turn = 0; 
    }

    void zero(function<void(int)> printNumber) {

        for (int k = 0; k < n; ++k) {
            unique_lock<mutex> lock(mtx);
            
            cv.wait(lock, [this]() { return turn == 0; });
            
            printNumber(0);

            turn = (i % 2 != 0) ? 1 : 2;
            
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int k = 0; k < (n + 1) / 2; ++k) {
            unique_lock<mutex> lock(mtx);
            
            cv.wait(lock, [this]() { return turn == 1; });
            
            printNumber(i);
            i++; 
            
            turn = 0;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int k = 0; k < n / 2; ++k) {
            unique_lock<mutex> lock(mtx);
            
            cv.wait(lock, [this]() { return turn == 2; });
            
            printNumber(i);
            i++; 

            turn = 0;
            cv.notify_all();
        }
    }
};