#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = colors.size();
        int max_dist = 0;

        // Sweep 1: Anchor at the Left Edge (0)
        // Scan backwards from the right edge to find the first mismatch
        for (int i = n - 1; i > 0; --i) {
            if (colors[i] != colors[0]) {
                max_dist = max(max_dist, i);
                break; // Stop immediately! Any further valid houses will have a smaller distance.
            }
        }

        // Sweep 2: Anchor at the Right Edge (n-1)
        // Scan forwards from the left edge to find the first mismatch
        for (int i = 0; i < n - 1; ++i) {
            if (colors[i] != colors[n - 1]) {
                max_dist = max(max_dist, n - 1 - i);
                break; // Stop immediately!
            }
        }

        return max_dist;
    }
};
