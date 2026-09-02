#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        double tower[102][102] = {0.0};

        // Pour everything into the top glass
        tower[0][0] = (double)poured;

        for (int r = 0; r <= query_row; ++r) {
            for (int c = 0; c <= r; ++c) {
                if (tower[r][c] > 1.0) {
                    // Calculate what flows down
                    double excess = (tower[r][c] - 1.0) / 2.0;
                    
                    tower[r + 1][c] += excess;
                    tower[r + 1][c + 1] += excess;

                }
            }
        }
        return min(1.0, tower[query_row][query_glass]);
    }
};