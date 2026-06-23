#include <vector>
#include <string>
#include <array>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = wordsContainer.size();

        int global_best_idx = 0;
        for (int i = 1; i < n; ++i) {
            if (wordsContainer[i].length() < wordsContainer[global_best_idx].length()) {
                global_best_idx = i;
            }
        }

        vector<array<int, 26>> trie;
        vector<int> best_idx;

        trie.reserve(500005);
        best_idx.reserve(500005);

        trie.push_back({});
        trie[0].fill(-1); 
        best_idx.push_back(global_best_idx);

        for (int i = 0; i < n; ++i) {
            int curr = 0;
            int curr_len = wordsContainer[i].length();
            
            for (int j = curr_len - 1; j >= 0; --j) {
                int char_idx = wordsContainer[i][j] - 'a';

                if (trie[curr][char_idx] == -1) {
                    trie[curr][char_idx] = trie.size(); 
                    trie.push_back({});              
                    trie.back().fill(-1);
                    best_idx.push_back(i);             
                }

                curr = trie[curr][char_idx];

                int best_len = wordsContainer[best_idx[curr]].length();
                if (curr_len < best_len || (curr_len == best_len && i < best_idx[curr])) {
                    best_idx[curr] = i;
                }
            }
        }

        vector<int> ans;
        ans.reserve(wordsQuery.size());
        
        for (const string& query : wordsQuery) {
            int curr = 0;
            int q_len = query.length();
            
            for (int j = q_len - 1; j >= 0; --j) {
                int char_idx = query[j] - 'a';
                
                if (trie[curr][char_idx] == -1) {
                    break;
                }
                curr = trie[curr][char_idx];
            }
            
            ans.push_back(best_idx[curr]);
        }

        return ans;
    }
};