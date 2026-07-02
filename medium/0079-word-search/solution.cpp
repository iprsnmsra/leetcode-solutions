#pragma GCC optimize("O3", "unroll-loops")
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = board.size();
        int n = board[0].size();
        int boardFreq[128] = {0};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boardFreq[board[i][j]]++;
            }
        }
        int wordFreq[128] = {0};
        for (char c : word) {
            wordFreq[c]++;
            if (wordFreq[c] > boardFreq[c]) {
                return false;
            }
        }
           
        if (boardFreq[word[0]] > boardFreq[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (board[i][j] == word[0] && dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        
        return false;
    }

private:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
     
        if (idx == word.length()) return true;
        
    
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }

      
        char temp = board[i][j];
        board[i][j] = '#'; 

      
        bool found = dfs(board, word, i + 1, j, idx + 1) ||
                     dfs(board, word, i - 1, j, idx + 1) ||
                     dfs(board, word, i, j + 1, idx + 1) ||
                     dfs(board, word, i, j - 1, idx + 1);

       
        board[i][j] = temp; 
        
        return found;
    }
};