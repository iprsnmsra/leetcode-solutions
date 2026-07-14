#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
    int dp[25][7][7][243];
    int p3[6]; // Precomputed powers of 3
    int m, n;
    int cost[3][3] = {
        {0,   0,   0},
        {0, -60, -10}, 
        {0, -10,  40}  
    };

    int dfs(int pos, int ic, int ec, int mask) {
        if (pos == m * n) return 0;
        if (dp[pos][ic][ec][mask] != -1) return dp[pos][ic][ec][mask];
        int up = mask / p3[n - 1]; 
        int left = (pos % n == 0) ? 0 : (mask % 3);

        int best = 0;
        int next_mask_empty = (mask % p3[n - 1]) * 3 + 0;
        best = max(best, dfs(pos + 1, ic, ec, next_mask_empty));
        if (ic > 0) {
            int next_mask_intro = (mask % p3[n - 1]) * 3 + 1;
            int score = 120 + cost[1][up] + cost[1][left];
            best = max(best, score + dfs(pos + 1, ic - 1, ec, next_mask_intro));
        }
        if (ec > 0) {
            int next_mask_extro = (mask % p3[n - 1]) * 3 + 2;
            int score = 40 + cost[2][up] + cost[2][left];
            best = max(best, score + dfs(pos + 1, ic, ec - 1, next_mask_extro));
        }

        return dp[pos][ic][ec][mask] = best;
    }

public:
    int getMaxGridHappiness(int m, int n, int introvertsCount, int extrovertsCount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (n > m) swap(n, m);
        this->m = m;
        this->n = n;
        p3[0] = 1;
        for (int i = 1; i <= n; ++i) p3[i] = p3[i - 1] * 3;

        memset(dp, -1, sizeof(dp));

        return dfs(0, introvertsCount, extrovertsCount, 0);
    }
};