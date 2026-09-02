#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int k;

public:
    KthLargest(int k, vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        this->k = k;
        for (int num : nums) {
            add(num);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < k) {
            minHeap.push(val);
        }
        // 2. If the heap is full, check if the new value qualifies to be in the top k
        else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val); // Add the new value
        }
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */