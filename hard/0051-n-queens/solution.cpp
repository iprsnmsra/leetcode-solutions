#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> posDiag(2 * n - 1, false);
        vector<bool> negDiag(2 * n - 1, false); 
        
        solve(0, n, board, result, cols, posDiag, negDiag);
        return result;
    }

private:
    void solve(int r, int n, vector<string>& board, vector<vector<string>>& result, 
               vector<bool>& cols, vector<bool>& posDiag, vector<bool>& negDiag) {

        if (r == n) {
            result.push_back(board);
            return;
        }

        for (int c = 0; c < n; ++c) {
            int d1 = r + c;
            int d2 = r - c + n - 1;

            if (cols[c] || posDiag[d1] || negDiag[d2]) {
                continue; 
            }

            board[r][c] = 'Q';
            cols[c] = posDiag[d1] = negDiag[d2] = true;

            solve(r + 1, n, board, result, cols, posDiag, negDiag);
            board[r][c] = '.';
            cols[c] = posDiag[d1] = negDiag[d2] = false;
        }
    }
};