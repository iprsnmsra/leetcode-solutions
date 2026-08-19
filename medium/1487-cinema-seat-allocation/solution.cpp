#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(reservedSeats.begin(), reservedSeats.end());

        int max_groups = 0;
        int reserved_rows_count = 0;
        int m = reservedSeats.size();
        int i = 0;
        while (i < m) {
            int current_row = reservedSeats[i][0];
            reserved_rows_count++;
            int row_mask = 0;
            while (i < m && reservedSeats[i][0] == current_row) {
                int seat = reservedSeats[i][1];
                if (seat >= 2 && seat <= 9) {
                    row_mask |= (1 << (seat - 2));
                }
                i++;
            }
            bool left_free = (row_mask & 15) == 0;
            bool right_free = (row_mask & 240) == 0;
            bool middle_free = (row_mask & 60) == 0;

            if (left_free && right_free) {
                max_groups += 2;
            } else if (left_free || right_free || middle_free) {
                max_groups += 1;
            }
        }
        max_groups += (n - reserved_rows_count) * 2;

        return max_groups;
    }
};