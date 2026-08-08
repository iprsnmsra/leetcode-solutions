#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<int, int> freq;
        for (int num : arr) {
            freq[num]++;
        }
        unordered_set<int> unique_freqs;
        for (auto const& [key, count] : freq) {
            if (!unique_freqs.insert(count).second) {
                return false;
            }
        }
        return true;
    }
};