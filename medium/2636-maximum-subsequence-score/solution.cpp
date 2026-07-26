#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums1.size();

        vector<pair<int, int>> pairs(n);
        for (int i = 0; i < n; ++i) {
            pairs[i] = {nums2[i], nums1[i]};
        }

        sort(pairs.rbegin(), pairs.rend());

        priority_queue<int, vector<int>, greater<int>> min_heap;
        long long current_sum = 0;
        long long max_score = 0;

        for (int i = 0; i < n; ++i) {
            int current_num2 = pairs[i].first;
            int current_num1 = pairs[i].second;

            min_heap.push(current_num1);
            current_sum += current_num1;

            if (min_heap.size() > k) {
                current_sum -= min_heap.top();
                min_heap.pop();
            }

            if (min_heap.size() == k) {
                long long current_score = current_sum * current_num2;
                if (current_score > max_score) {
                    max_score = current_score;
                }
            }
        }

        return max_score;
    }
};