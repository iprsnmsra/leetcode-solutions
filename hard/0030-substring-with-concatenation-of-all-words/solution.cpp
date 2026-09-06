#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result;
        int n = s.length();
        int m = words.size();
        if (n == 0 || m == 0) return result;
        
        int w = words[0].length();
        // Early exit if s is shorter than the required concatenation
        if (n < (long long)m * w) return result;

        // Step 1: Map strings to unique Integer IDs
        unordered_map<string, int> map;
        vector<int> expected; // Stores the count required for each ID
        
        for (const string& word : words) {
            if (map.find(word) == map.end()) {
                map[word] = expected.size(); // Assign new ID
                expected.push_back(1);
            } else {
                expected[map[word]]++;
            }
        }
        
        int unique = expected.size();
        
        // Step 2: Create the "Token Array" 
        // table[i] holds the Word ID starting at s[i], or -1 if invalid
        vector<int> table(n, -1);
        for (int i = 0; i <= n - w; ++i) {
            string sub = s.substr(i, w);
            if (map.count(sub)) {
                table[i] = map[sub];
            }
        }

        // Step 3: Sliding Window on Integer IDs
        // We reuse this vector to save memory allocation overhead
        vector<int> window(unique, 0);

        // We run 'w' passes to cover all possible alignments
        for (int i = 0; i < w; ++i) {
            int left = i, right = i, count = 0;
            fill(window.begin(), window.end(), 0); 
            
            while (right <= n - w) {
                int id = table[right];
                
                if (id != -1) {
                    window[id]++;
                    count++;
                    
                    // If we have too many of this word, shrink from left
                    while (window[id] > expected[id]) {
                        int leftId = table[left];
                        window[leftId]--;
                        count--;
                        left += w;
                    }
                    
                    // If valid word count matches 'm', we found a solution
                    if (count == m) {
                        result.push_back(left);
                        // Slide window forward to look for next match
                        window[table[left]]--;
                        count--;
                        left += w;
                    }
                } else {
                    // Invalid word breaks the chain. Reset.
                    fill(window.begin(), window.end(), 0);
                    count = 0;
                    left = right + w;
                }
                right += w;
            }
        }
        
        return result;
    }
};