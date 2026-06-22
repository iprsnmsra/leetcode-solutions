#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {

    long long memo_paths[20][11][11][2];
    long long memo_wave[20][11][11][2];
    string num_str;

    pair<long long, long long> dfs(int idx, int p2, int p1, bool is_tight, bool is_started) {

        if (idx == num_str.length()) {
            return {1, 0}; 
        }

        if (!is_tight && memo_paths[idx][p2][p1][is_started] != -1) {
            return {memo_paths[idx][p2][p1][is_started], memo_wave[idx][p2][p1][is_started]};
        }

        int limit = is_tight ? num_str[idx] - '0' : 9;
        long long total_paths = 0;
        long long total_wave = 0;

        for (int d = 0; d <= limit; ++d) {
            bool next_tight = is_tight && (d == limit);
            bool next_started = is_started || (d > 0);

            int next_p2 = 10, next_p1 = 10;
            long long wave_added = 0;

            if (next_started) {
                if (!is_started) {

                    next_p1 = d;
                } else if (p2 == 10) {

                    next_p2 = p1;
                    next_p1 = d;
                } else {

                    next_p2 = p1;
                    next_p1 = d;
                    
                    if ((p1 > p2 && p1 > d) || (p1 < p2 && p1 < d)) {
                        wave_added = 1;
                    }
                }
            }

            auto [child_paths, child_wave] = dfs(idx + 1, next_p2, next_p1, next_tight, next_started);

            total_paths += child_paths;

            total_wave += child_wave + (child_paths * wave_added);
        }

        if (!is_tight) {
            memo_paths[idx][p2][p1][is_started] = total_paths;
            memo_wave[idx][p2][p1][is_started] = total_wave;
        }

        return {total_paths, total_wave};
    }

    long long solve(long long n) {
        if (n < 100) return 0;
        num_str = to_string(n);
        memset(memo_paths, -1, sizeof(memo_paths));
        memset(memo_wave, -1, sizeof(memo_wave));
        
        return dfs(0, 10, 10, true, false).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return solve(num2) - solve(num1 - 1);
    }
};