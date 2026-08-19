#include <vector>
#include <iostream>

using namespace std;

class Solution {
private:
    int rows[9] = {0};
    int cols[9] = {0};
    int boxes[9] = {0};
    vector<pair<int, int>> empty_cells;

    bool solve(vector<vector<char>>& board, int idx) {
        if (idx == empty_cells.size()) {
            return true;
        }
        int r = empty_cells[idx].first;
        int c = empty_cells[idx].second;
        int box_idx = (r / 3) * 3 + (c / 3);
        for (int val = 1; val <= 9; ++val) {
            int mask = 1 << val;
            if (!(rows[r] & mask) && !(cols[c] & mask) && !(boxes[box_idx] & mask)) {
                rows[r] |= mask;
                cols[c] |= mask;
                boxes[box_idx] |= mask;
                board[r][c] = val + '0';
                if (solve(board, idx + 1)) {
                    return true; // We found the winning path!
                }
                rows[r] ^= mask;
                cols[c] ^= mask;
                boxes[box_idx] ^= mask;
                board[r][c] = '.';
            }
        }
        return false; 
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    empty_cells.push_back({r, c});
                } else {
                    int val = board[r][c] - '0';
                    int mask = 1 << val;
                    int box_idx = (r / 3) * 3 + (c / 3);
                    
                    rows[r] |= mask;
                    cols[c] |= mask;
                    boxes[box_idx] |= mask;
                }
            }
        }
        solve(board, 0);
    }
};