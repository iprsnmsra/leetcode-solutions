#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = words.size();
        int min_dist = 1e9; 

        for (int i = 0; i < n; ++i) {

            if (words[i] == target) {

                int direct_dist = abs(i - startIndex);

                int wrap_dist = n - direct_dist;

                int shortest_arc = min(direct_dist, wrap_dist);

                if (shortest_arc < min_dist) {
                    min_dist = shortest_arc;
                }
            }
        }
        return min_dist == 1e9 ? -1 : min_dist;
    }
};