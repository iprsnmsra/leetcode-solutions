#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_price = INT_MAX;

        int max_profit = 0;

        for (int price : prices) {

            if (price < min_price) {
                min_price = price;
            } 
            else if (price - min_price > max_profit) {
                max_profit = price - min_price;
            }
        }

        return max_profit;
    }
};