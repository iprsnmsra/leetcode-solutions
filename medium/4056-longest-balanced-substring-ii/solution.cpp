#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestBalanced(string s) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_len = 0;
        int n = s.length();

        // ---------------------------------------------------------
        // Case 1: Single Characters (Subsets {a}, {b}, {c})
        // ---------------------------------------------------------
        int current_run = 0;
        for (int i = 0; i < n; ++i) {
            if (i > 0 && s[i] == s[i-1]) {
                current_run++;
            } else {
                current_run = 1;
            }
            max_len = max(max_len, current_run);
        }

        // ---------------------------------------------------------
        // Case 2: Two Characters (Subsets {a,b}, {a,c}, {b,c})
        // ---------------------------------------------------------
        // We run the helper 3 times, once for each pair, treating the 3rd char as "forbidden"
        max_len = max(max_len, solveTwo(s, 'a', 'b', 'c')); // Ignore c
        max_len = max(max_len, solveTwo(s, 'a', 'c', 'b')); // Ignore b
        max_len = max(max_len, solveTwo(s, 'b', 'c', 'a')); // Ignore a

        // ---------------------------------------------------------
        // Case 3: Three Characters (Subset {a,b,c})
        // ---------------------------------------------------------
        // We need count(a) == count(b) == count(c)
        // Transform to: count(a)-count(b) == 0 AND count(b)-count(c) == 0
        // Map Key: string "diff1,diff2" or a combined hash
        unordered_map<string, int> map;
        map["0,0"] = -1;
        
        int a = 0, b = 0, c = 0;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') a++;
            else if (s[i] == 'b') b++;
            else if (s[i] == 'c') c++;
            
            int diff1 = a - b;
            int diff2 = b - c;
            
            string key = to_string(diff1) + "," + to_string(diff2);
            
            if (map.count(key)) {
                max_len = max(max_len, i - map[key]);
            } else {
                map[key] = i;
            }
        }

        return max_len;
    }

private:
    int solveTwo(const string& s, char c1, char c2, char forbidden) {
        int local_max = 0;
        // Map stores: diff -> first_index
        // Diff = count(c1) - count(c2)
        // We use a vector for the map with offset to avoid expensive unordered_map
        // Max diff is N, min is -N. Size 2N+1.
        // However, s.length up to 10^5 makes vector fast but large. 
        // Given constraints, unordered_map is safer for memory, or a reused static vector.
        // Let's use unordered_map for simplicity and safety.
        unordered_map<int, int> mp;
        mp[0] = -1;
        
        int diff = 0;
        int start_index = 0; // Where the current valid segment (no forbidden chars) began

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == forbidden) {
                // Reset everything
                mp.clear();
                mp[0] = i; // Conceptually the diff is 0 relative to this new start
                diff = 0;
                continue;
            }

            if (s[i] == c1) diff++;
            else if (s[i] == c2) diff--;

            if (mp.count(diff)) {
                local_max = max(local_max, i - mp[diff]);
            } else {
                mp[diff] = i;
            }
        }
        return local_max;
    }
};