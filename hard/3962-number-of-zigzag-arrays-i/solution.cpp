#include <vector>
#include <iostream>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    
public:
    int zigZagArrays(int n, int l, int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int k = r - l + 1;
        vector<int> dp_down(k + 1, 1);
        vector<int> dp_up(k + 1, 1);
        
        vector<int> next_dp_down(k + 1, 0);
        vector<int> next_dp_up(k + 1, 0);
        
        vector<long long> pref_down(k + 2, 0);
        vector<long long> pref_up(k + 2, 0);
        for (int i = 2; i <= n; ++i) {
            long long current_pref_down = 0;
            long long current_pref_up = 0;
            for (int j = 1; j <= k; ++j) {
                current_pref_down = (current_pref_down + dp_down[j]) % MOD;
                pref_down[j] = current_pref_down;
                
                current_pref_up = (current_pref_up + dp_up[j]) % MOD;
                pref_up[j] = current_pref_up;
            }

            long long total_up = pref_up[k];
            for (int j = 1; j <= k; ++j) {
                next_dp_down[j] = (total_up - pref_up[j] + MOD) % MOD;
                next_dp_up[j] = pref_down[j - 1];
            }
            swap(dp_down, next_dp_down);
            swap(dp_up, next_dp_up);
        }
        long long total_valid = 0;
        for (int j = 1; j <= k; ++j) {
            total_valid = (total_valid + dp_down[j] + dp_up[j]) % MOD;
        }

        return total_valid;
    }
};