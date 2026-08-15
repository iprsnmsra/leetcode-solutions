#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
            // Optimization: Fast I/O
                    ios_base::sync_with_stdio(false);
                            cin.tie(NULL);

                                    int n = mat.size();
                                            
                                                    // Assume all 4 rotations are valid until proven otherwise
                                                            bool deg0 = true, deg90 = true, deg180 = true, deg270 = true;

                                                                    for (int r = 0; r < n; ++r) {
                                                                                for (int c = 0; c < n; ++c) {
                                                                                                
                                                                                                                // Compare target against the 4 mathematical rotation mappings
                                                                                                                                if (mat[r][c] != target[r][c]) {
                                                                                                                                                    deg0 = false;
                                                                                                                                                                    }
                                                                                                                                                                                    if (mat[n - 1 - c][r] != target[r][c]) {
                                                                                                                                                                                                        deg90 = false;
                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                        if (mat[n - 1 - r][n - 1 - c] != target[r][c]) {
                                                                                                                                                                                                                                                            deg180 = false;
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                            if (mat[c][n - 1 - r] != target[r][c]) {
                                                                                                                                                                                                                                                                                                                deg270 = false;
                                                                                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                                                                                                // HARDWARE EMPATHY: Aggressive Early Exit
                                                                                                                                                                                                                                                                                                                                                                // If all 4 possibilities are dead, stop scanning the matrix entirely!
                                                                                                                                                                                                                                                                                                                                                                                if (!deg0 && !deg90 && !deg180 && !deg270) {
                                                                                                                                                                                                                                                                                                                                                                                                    return false;
                                                                                                                                                                                                                                                                                                                                                                                                                    }
                                                                                                                                                                                                                                                                                                                                                                                                                                }
                                                                                                                                                                                                                                                                                                                                                                                                                                        }

                                                                                                                                                                                                                                                                                                                                                                                                                                                // If any of the flags survived the entire scan, a valid rotation exists!
                                                                                                                                                                                                                                                                                                                                                                                                                                                        return deg0 || deg90 || deg180 || deg270;
                                                                                                                                                                                                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                                                                                                                                                                                                            };