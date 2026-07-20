#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left_count = 0;
        int right_count = 0;
        int wild_count = 0;

        for (char move : moves) {
            if (move == 'L') {
                left_count++;
            } else if (move == 'R') {
                right_count++;
            } else {
                wild_count++;
            }
        }

        return abs(left_count - right_count) + wild_count;
    }
};