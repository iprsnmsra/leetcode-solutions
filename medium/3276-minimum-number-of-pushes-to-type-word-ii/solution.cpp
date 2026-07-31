#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Data Abstraction: Stack-allocated contiguous integer array
        int freq[26] = {0};

        // 2. The Linear Frequency Sweep
        for (char c : word) {
            freq[c - 'a']++;
        }

        // 3. O(1) Sort: Sort the 26 elements in strictly descending order
        sort(freq, freq + 26, greater<int>());

        int total_pushes = 0;

        // 4. The Algebraic Scalar Resolution
        for (int i = 0; i < 26; ++i) {
            // Short-circuit: The array is sorted descending. 
            // Once we hit 0, there are no more characters to map.
            if (freq[i] == 0) break;

            // A bitwise right-shift by 3 maps perfectly to dividing by 8.
            // i = 0..7   -> (i >> 3) == 0 -> Cost: 1
            // i = 8..15  -> (i >> 3) == 1 -> Cost: 2
            int depth = (i >> 3) + 1;
            
            total_pushes += freq[i] * depth;
        }

        return total_pushes;
    }
};