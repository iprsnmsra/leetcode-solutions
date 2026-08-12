#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = candies.size();

        int max_candies = *max_element(candies.begin(), candies.end());

        vector<bool> result(n);

        for (int i = 0; i < n; ++i) {
            result[i] = (candies[i] + extraCandies >= max_candies);
        }
        
        return result;
    }
};