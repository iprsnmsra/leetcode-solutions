#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minOperations(string s) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();

        // 1. O(N) Check: Already Sorted (0 Operations)
        if (is_sorted(s.begin(), s.end())) {
            return 0;
        }

        // 2. Base Case: Length 2 Unsorted is Impossible (-1)
        if (n == 2) {
            return -1;
        }

        char min_char = *min_element(s.begin(), s.end());
        char max_char = *max_element(s.begin(), s.end());

        // 3. O(N) Check: 1 Operation Boundary Match
        if (s[0] == min_char || s[n - 1] == max_char) {
            return 1;
        }

        // 4. O(N) Check: 3 Operations Worst-Case Condition
        // Requires s[0] to be UNIQUE max AND s[n-1] to be UNIQUE min
        bool max_is_unique_at_start = (s[0] == max_char) && (count(s.begin(), s.end(), max_char) == 1);
        bool min_is_unique_at_end = (s[n - 1] == min_char) && (count(s.begin(), s.end(), min_char) == 1);

        if (max_is_unique_at_start && min_is_unique_at_end) {
            return 3;
        }

        // 5. Otherwise, 2 Operations Suffice
        return 2;
    }
};