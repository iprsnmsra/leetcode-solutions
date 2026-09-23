class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int live_neighbors = 0;
                for (int I = max(i - 1, 0); I < min(i + 2, m); ++I) {
                    for (int J = max(j - 1, 0); J < min(j + 2, n); ++J) {
                        live_neighbors += board[I][J] & 1;
                    }
                }
                live_neighbors -= board[i][j] & 1;
                if (board[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3)) {
                    board[i][j] |= 2; 
                }
                if (board[i][j] == 0 && live_neighbors == 3) {
                    board[i][j] |= 2; 
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] >>= 1;
            }
        }
    }
};