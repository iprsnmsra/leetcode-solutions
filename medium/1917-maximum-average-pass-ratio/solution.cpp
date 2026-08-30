#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        auto get_gain = [](double pass, double total) {
            return ((pass + 1.0) / (total + 1.0)) - (pass / total);
        };
        priority_queue<pair<double, pair<int, int>>> max_heap;
        for (const auto& c : classes) {
            max_heap.push({get_gain(c[0], c[1]), {c[0], c[1]}});
        }

        while (extraStudents > 0) {

            auto [current_gain, counts] = max_heap.top();
            max_heap.pop();

            int p = counts.first + 1;
            int t = counts.second + 1;
            max_heap.push({get_gain(p, t), {p, t}});
            
            extraStudents--;
        }
        double total_ratio = 0.0;
        while (!max_heap.empty()) {
            auto [gain, counts] = max_heap.top();
            max_heap.pop();
            total_ratio += (double)counts.first / counts.second;
        }

        return total_ratio / classes.size();
    }
};