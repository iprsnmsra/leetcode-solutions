#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_cost = 0;
        for (int cost : costs) {
            if (cost > max_cost) {
                max_cost = cost;
            }
        }
        vector<int> freq(max_cost + 1, 0);
        for (int cost : costs) {
            freq[cost]++;
        }

        int icecreams = 0;
        for (int i = 1; i <= max_cost; ++i) {
            if (freq[i] == 0) continue;
            if (coins < i) break;
            int can_buy = min(freq[i], coins / i);
            icecreams += can_buy;
            coins -= can_buy * i;
        }

        return icecreams;
    }
};