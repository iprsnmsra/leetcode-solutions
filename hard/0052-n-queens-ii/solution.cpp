#include <iostream>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int board_mask = (1 << n) - 1; 

     
        return solve(0, 0, 0, 0, board_mask);
    }

private:
    int solve(int row, int cols, int left_diags, int right_diags, int board_mask) {
        if (row == board_mask) {

        }

        if (cols == board_mask) {
            return 1; 
        }

        int solutions = 0;

        int available_spots = ~(cols | left_diags | right_diags) & board_mask;

        while (available_spots) {

            int pos = available_spots & -available_spots;

            available_spots &= available_spots - 1;

            solutions += solve(
                row + 1, 
                cols | pos, 
                (left_diags | pos) << 1, 
                (right_diags | pos) >> 1, 
                board_mask
            );
        }

        return solutions;
    }
};