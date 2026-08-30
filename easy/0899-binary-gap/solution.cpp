#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int binaryGap(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_gap = 0;
        int last_seen_1_position = -1;
        int current_position = 0;
        while (n > 0) {
           
            if ((n & 1) == 1) {
         
                if (last_seen_1_position != -1) {
                    max_gap = max(max_gap, current_position - last_seen_1_position);
                }
                last_seen_1_position = current_position;
            }
            current_position++;
            n >>= 1; 
        }

        return max_gap;
    }
};