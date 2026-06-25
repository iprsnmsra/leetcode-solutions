#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_map<string, vector<string>> anagram_map;
        
        for (const string& s : strs) {
            string key(26, 0); 

            for (char c : s) {
                key[c - 'a']++;
            }
            anagram_map[key].push_back(s);
        }
        
        vector<vector<string>> result;
        result.reserve(anagram_map.size());
        
        for (auto& pair : anagram_map) {
            result.push_back(std::move(pair.second)); 
        }
        
        return result;
    }
};