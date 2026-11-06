#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Sort the target array to enable O(log M) spatial queries
        sort(arr2.begin(), arr2.end());

        int distance_value = 0;

        // 2. Hardware-accelerated L1 sweep of arr1
        for (int x : arr1) {
            
            // Extract the first element in arr2 that crosses the left boundary: (x - d)
            auto it = lower_bound(arr2.begin(), arr2.end(), x - d);

            // 3. O(1) Right Boundary Verification
            // If the element exists and sits strictly inside [x - d, x + d], the distance is violated.
            if (it != arr2.end() && *it <= x + d) {
                continue; 
            }

            // No elements in arr2 breached the [x - d, x + d] zone
            distance_value++;
        }

        return distance_value;
    }
};