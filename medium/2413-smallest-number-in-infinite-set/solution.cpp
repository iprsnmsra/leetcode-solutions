#include <queue>
#include <unordered_set>

using namespace std;

class SmallestInfiniteSet {
private:
    int current; 
    priority_queue<int, vector<int>, greater<int>> min_heap; 
    unordered_set<int> is_in_heap; 

public:
    SmallestInfiniteSet() {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        current = 1;
    }
    
    int popSmallest() {

        if (!min_heap.empty()) {
            int smallest = min_heap.top();
            min_heap.pop();
            is_in_heap.erase(smallest);
            return smallest;
        }

        int res = current;
        current++;
        return res;
    }
    
    void addBack(int num) {

        if (num < current && is_in_heap.find(num) == is_in_heap.end()) {
            min_heap.push(num);
            is_in_heap.insert(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */