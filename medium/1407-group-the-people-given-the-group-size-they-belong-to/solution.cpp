#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = groupSizes.size();
        vector<vector<int>> result;
        vector<vector<int>> buckets(n + 1);
        for (int i = 0; i < n; ++i) {
            int size = groupSizes[i];
            buckets[size].push_back(i);
            if (buckets[size].size() == size) {
                result.push_back(buckets[size]);
                buckets[size].clear();
            }
        }

        return result;
    }
};