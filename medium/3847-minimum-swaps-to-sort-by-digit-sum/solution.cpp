#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // 1. Hardware-Aligned Memory Binding
    // A flat struct guarantees perfect L1 cache contiguity during std::sort.
    struct Element {
        int val;
        int digit_sum;
        int orig_idx;
        
        // Strict-weak ordering prioritizing digit sum, then base value.
        bool operator<(const Element& other) const {
            if (digit_sum != other.digit_sum) {
                return digit_sum < other.digit_sum;
            }
            return val < other.val;
        }
    };

    // Fast ALU-based modulo arithmetic (Zero String Conversions)
    inline int getDigitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<Element> arr(n);
        
        for (int i = 0; i < n; ++i) {
            arr[i] = {nums[i], getDigitSum(nums[i]), i};
        }

        // 2. State Generation
        // Executes in O(N log N) using IntroSort. 
        sort(arr.begin(), arr.end());

        // 3. Permutation Cycle Extraction
        int swaps = 0;
        
        // Using vector<uint8_t> over vector<bool>. 
        // vector<bool> is implemented as a bitfield proxy which destroys speed. 
        // uint8_t maps purely to a 1-byte raw boolean array, maximizing FPU speed.
        vector<uint8_t> visited(n, 0);

        for (int i = 0; i < n; ++i) {
            // Skip elements already in the right place or processed in a previous cycle
            if (visited[i] || arr[i].orig_idx == i) {
                continue;
            }

            // 4. Graph Cycle Traversal
            int cycle_length = 0;
            int j = i;
            
            while (!visited[j]) {
                visited[j] = 1;
                j = arr[j].orig_idx; // Pointer Jump to the next node in the permutation ring
                cycle_length++;
            }

            // 5. Mathematical Resolution
            if (cycle_length > 1) {
                swaps += (cycle_length - 1);
            }
        }

        return swaps;
    }
};