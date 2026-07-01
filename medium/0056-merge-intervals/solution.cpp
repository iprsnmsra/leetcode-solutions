#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (intervals.empty()) return {};


        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;

        merged.push_back(intervals[0]);

 
        for (int i = 1; i < intervals.size(); i++) {

            vector<int>& last_merged = merged.back();

            if (intervals[i][0] <= last_merged[1]) {

                last_merged[1] = max(last_merged[1], intervals[i][1]);
            } else {
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};