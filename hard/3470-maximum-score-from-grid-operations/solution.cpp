#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
    long long pref[105][105];
    long long prev_dp[105][105];
    long long curr_dp[105][105];
    inline long long get_score(int col, int curr_h, int M) {
        if (M > curr_h) {
            return pref[col][M] - pref[col][curr_h];
        }
        return 0; 
    }

public:
    long long maximumScore(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = grid.size();

        for (int j = 0; j < n; ++j) {
            pref[j][0] = 0;
            for (int i = 0; i < n; ++i) {
                pref[j][i + 1] = pref[j][i] + grid[i][j];
            }
        }

        for (int curr = 0; curr <= n; ++curr) {
            for (int nxt = 0; nxt <= n; ++nxt) {
                prev_dp[curr][nxt] = get_score(0, curr, nxt);
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int curr = 0; curr <= n; ++curr) {

                long long prefix_max[105];
                prefix_max[0] = prev_dp[0][curr];
                for (int p = 1; p <= n; ++p) {
                    prefix_max[p] = max(prefix_max[p - 1], prev_dp[p][curr]);
                }

                long long suffix_max[105];
                suffix_max[n + 1] = -1e18; 
                for (int p = n; p >= 0; --p) {
                    long long val = prev_dp[p][curr] + get_score(i, curr, p);
                    suffix_max[p] = max(suffix_max[p + 1], val);
                }

                for (int nxt = 0; nxt <= n; ++nxt) {

                    long long opt1 = prefix_max[nxt] + get_score(i, curr, nxt);
                    

                    long long opt2 = suffix_max[nxt + 1];
                    
                    curr_dp[curr][nxt] = max(opt1, opt2);
                }
            }

            for (int curr = 0; curr <= n; ++curr) {
                for (int nxt = 0; nxt <= n; ++nxt) {
                    prev_dp[curr][nxt] = curr_dp[curr][nxt];
                }
            }
        }

        long long ans = 0;
        for (int curr = 0; curr <= n; ++curr) {
            ans = max(ans, prev_dp[curr][0]);
        }

        return ans;
    }
};