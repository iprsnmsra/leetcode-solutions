#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int num : nums) {

            min_heap.push(num);

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        return min_heap.top();
    }
};