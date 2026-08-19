#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

class Solution {
private:
    int dp[25][405];
    const int MOD = 1e9 + 7;
    int solve(const string& num, int idx, int current_sum, bool is_tight, int min_sum, int max_sum) {
        if (current_sum > max_sum) {
            return 0;
        }
        if (idx == num.length()) {
            return (current_sum >= min_sum) ? 1 : 0;
        }
        if (!is_tight && dp[idx][current_sum] != -1) {
            return dp[idx][current_sum];
        }
        int limit = is_tight ? (num[idx] - '0') : 9;
        int total_valid_paths = 0;
        for (int d = 0; d <= limit; ++d) {
            bool next_is_tight = is_tight && (d == limit);
            total_valid_paths = (total_valid_paths + 
                                 solve(num, idx + 1, current_sum + d, next_is_tight, min_sum, max_sum)) % MOD;
        }
        if (!is_tight) {
            dp[idx][current_sum] = total_valid_paths;
        }

        return total_valid_paths;
    }

    int getCount(const string& num, int min_sum, int max_sum) {
        memset(dp, -1, sizeof(dp));
        return solve(num, 0, 0, true, min_sum, max_sum);
    }

public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count2 = getCount(num2, min_sum, max_sum);
        int count1 = getCount(num1, min_sum, max_sum);
        int num1_sum = 0;
        for (char c : num1) {
            num1_sum += c - '0';
        }
        int is_num1_valid = (num1_sum >= min_sum && num1_sum <= max_sum) ? 1 : 0;
        return (count2 - count1 + is_num1_valid + MOD) % MOD;
    }
};