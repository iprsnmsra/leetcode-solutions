#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(cost.begin(), cost.end(), greater<int>());

        int total_cost = 0;

        for (int i = 0; i < cost.size(); ++i) {

            if ((i + 1) % 3 != 0) {
                total_cost += cost[i];
            }
        }

        return total_cost;
    }
};