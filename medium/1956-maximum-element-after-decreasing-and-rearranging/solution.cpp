#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = arr.size();
        vector<int> counts(n + 1, 0);
        
        for (int num : arr) {
            counts[min(num, n)]++;
        }
        
        int current_max = 0;
        for (int i = 1; i <= n; ++i) {
            current_max = min(current_max + counts[i], i);
        }
        
        return current_max;
    }
};