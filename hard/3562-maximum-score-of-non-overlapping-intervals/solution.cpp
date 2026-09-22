#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 1. Data Abstraction: Hardware-native Interval Tracker
struct Interval {
    int start, end, weight, id;
    
    // Sort strictly by temporal start time to enable DP binary search
    bool operator<(const Interval& other) const {
        if (start != other.start) return start < other.start;
        return id < other.id;
    }
};

// 2. Data Abstraction: 32-Byte Aligned State Register
// Bypasses std::vector to eradicate OS heap allocations during DP transitions
struct Result {
    long long weight;
    int size;
    int ids[4];

    Result() : weight(0), size(0) {}

    // Lexicographical Tie-Breaker Logic
    bool is_better_than(const Result& other) const {
        if (weight != other.weight) return weight > other.weight;
        
        for (int i = 0; i < min(size, other.size); ++i) {
            if (ids[i] != other.ids[i]) return ids[i] < other.ids[i];
        }
        return size < other.size;
    }
};

class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals_in) {
        // Optimization: Fast I/O for competitive programming speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = intervals_in.size();
        vector<Interval> intervals(n);
        vector<int> starts(n);
        
        for (int i = 0; i < n; ++i) {
            intervals[i] = {intervals_in[i][0], intervals_in[i][1], intervals_in[i][2], i};
        }
        
        sort(intervals.begin(), intervals.end());
        
        for (int i = 0; i < n; ++i) {
            starts[i] = intervals[i].start;
        }

        // 3. Monolithic Heap Allocation:
        // A flattened 1D array guarantees localized L1/L2 Cache execution.
        // Size: 50,000 * 5 * 32 bytes = ~8 Megabytes of contiguous RAM.
        vector<Result> dp((n + 1) * 5);

        // 4. The Backward DP Sweep
        for (int i = n - 1; i >= 0; --i) {
            // Find the next non-overlapping interval in O(log N)
            int j = upper_bound(starts.begin(), starts.end(), intervals[i].end) - starts.begin();
            
            for (int k = 1; k <= 4; ++k) {
                // Option 1: Skip the current interval
                Result best = dp[(i + 1) * 5 + k];
                
                // Option 2: Take the current interval
                Result take;
                const Result& next_res = dp[j * 5 + (k - 1)];
                take.weight = intervals[i].weight + next_res.weight;
                take.size = next_res.size + 1;
                
                // Hardware-level Unrolled Insertion Sort (Since N <= 4)
                int curr_id = intervals[i].id;
                int p = 0;
                bool inserted = false;
                
                for (int m = 0; m < next_res.size; ++m) {
                    if (!inserted && curr_id < next_res.ids[m]) {
                        take.ids[p++] = curr_id;
                        inserted = true;
                    }
                    take.ids[p++] = next_res.ids[m];
                }
                
                if (!inserted) {
                    take.ids[p++] = curr_id;
                }
                
                // O(1) Lexicographical Evaluation
                if (take.is_better_than(best)) {
                    best = take;
                }
                
                dp[i * 5 + k] = best;
            }
        }

        // 5. Payload Extraction
        Result final_res = dp[0 * 5 + 4];
        vector<int> ans;
        ans.reserve(final_res.size);
        for (int i = 0; i < final_res.size; ++i) {
            ans.push_back(final_res.ids[i]);
        }
        
        return ans;
    }
};