#include <queue>
#include <vector>

using namespace std;

class MedianFinder {
private:
    priority_queue<int> low_half;
    
    priority_queue<int, vector<int>, greater<int>> high_half;

public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        low_half.push(num);
        high_half.push(low_half.top());
        low_half.pop();
        if (high_half.size() > low_half.size()) {
            low_half.push(high_half.top());
            high_half.pop();
        }
    }
    
    double findMedian() {
        if (low_half.size() > high_half.size()) {
            return low_half.top();
        }
        return (low_half.top() + high_half.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */