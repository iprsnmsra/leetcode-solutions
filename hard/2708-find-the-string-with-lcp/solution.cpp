#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = lcp.size();
        string word(n, ' '); 
        char currentChar = 'a';
        for (int i = 0; i < n; ++i) {
            if (word[i] == ' ') {
                if (currentChar > 'z') return ""; 
                for (int j = i; j < n; ++j) {
                    if (lcp[i][j] > 0) {
                        word[j] = currentChar;
                    }
                }
                currentChar++; 
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                
                int expected_lcp = 0;
                
                if (word[i] == word[j]) {
                    expected_lcp = (i + 1 < n && j + 1 < n) ? lcp[i + 1][j + 1] + 1 : 1;
                }
                if (lcp[i][j] != expected_lcp) {
                    return "";
                }
            }
        }

        return word;
    }
};