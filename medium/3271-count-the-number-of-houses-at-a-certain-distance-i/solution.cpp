#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result(n, 0);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i == j) continue;
                int dist1 = abs(i - j);
                int dist3 = abs(i - x) + 1 + abs(y - j);
                int dist2 = abs(i - y) + 1 + abs(x - j);

                int shortest = min({dist1, dist2, dist3});
                result[shortest - 1]++;
            }
        }

        return result;
    }
};