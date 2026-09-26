#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. O(1) Hash Map Initialization
        // We load the data dictionary into an unordered map for instant ALU lookups
        unordered_map<string, string> dict;
        dict.reserve(knowledge.size()); // Pre-allocate bucket count to avoid re-hashing
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result;
        // 2. Heap Pre-allocation
        // We guarantee the OS provisions enough contiguous RAM immediately.
        result.reserve(s.length()); 

        int start_idx = -1; // -1 represents the "Prose" state. >= 0 represents the "Key" state.

        // 3. The Single O(N) Lexical Forward Sweep
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Shift state to Key parsing. Mark the physical start boundary.
                start_idx = i + 1;
            } 
            else if (s[i] == ')') {
                // Calculate physical memory length without copying characters
                int len = i - start_idx;
                
                // Extract contiguous memory chunk (SSO optimizes this to zero-heap allocation since len <= 10)
                string key = s.substr(start_idx, len);
                
                // Hash Map Lookup
                auto it = dict.find(key);
                if (it != dict.end()) {
                    result += it->second;
                } else {
                    result += '?';
                }
                
                // Shift state back to Prose parsing
                start_idx = -1;
            } 
            else if (start_idx == -1) {
                // Hardware-level character pushing
                result += s[i];
            }
        }

        return result;
    }
};