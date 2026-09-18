#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = img1.size();
        
        // 1. Data Compression: 32-Bit Hardware Encoding
        // Completely eradicates 2D array overhead, compressing the spatial grid into flat L1 cache memory.
        vector<uint32_t> a(n, 0), b(n, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j]) a[i] |= (1U << j);
                if (img2[i][j]) b[i] |= (1U << j);
            }
        }

        int max_overlap = 0;

        // 2. The Spatial Convolution Sweep
        for (int y = -(n - 1); y < n; ++y) {
            for (int x = -(n - 1); x < n; ++x) {
                int overlap = 0;
                
                // 3. Row-by-Row Hardware Intersection
                // Safely bounded to only process rows that physically overlap vertically
                for (int i = max(0, -y); i < min(n, n - y); ++i) {
                    uint32_t r1 = a[i];
                    uint32_t r2 = b[i + y];
                    
                    // Spatial horizontal translation flawlessly mapped to a native ALU bit-shift
                    uint32_t shifted_r1 = (x >= 0) ? (r1 << x) : (r1 >> (-x));
                    
                    // Hardware bitwise intersection & population count
                    overlap += __builtin_popcount(shifted_r1 & r2);
                }
                
                if (overlap > max_overlap) {
                    max_overlap = overlap;
                }
            }
        }

        return max_overlap;
    }
};