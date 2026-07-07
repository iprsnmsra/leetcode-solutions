#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        int h = k / 2;
        long long base_profit = 0;
        for (int i = 0; i < n; ++i) {
            base_profit += (long long)strategy[i] * prices[i];
        }

        auto get_g1 = [&](int i) { return (0LL - strategy[i]) * prices[i]; };
        auto get_g2 = [&](int i) { return (1LL - strategy[i]) * prices[i]; };
        
        long long current_delta = 0;

        for (int i = 0; i < h; ++i) current_delta += get_g1(i);
        for (int i = h; i < k; ++i) current_delta += get_g2(i);
        
        long long max_delta = current_delta;
        for (int i = 0; i < n - k; ++i) {

            current_delta -= get_g1(i);

            current_delta += get_g1(i + h);
            current_delta -= get_g2(i + h);

            current_delta += get_g2(i + k);
            
            max_delta = max(max_delta, current_delta);
        }

        return base_profit + max(0LL, max_delta);
    }
};