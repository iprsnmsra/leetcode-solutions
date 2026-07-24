#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int free = 0; 

        int hold = -prices[0]; 

        for (int i = 1; i < prices.size(); ++i) {

            
            int next_free = max(free, hold + prices[i] - fee);
            int next_hold = max(hold, free - prices[i]);

            free = next_free;
            hold = next_hold;
        }

        return free;
    }
};