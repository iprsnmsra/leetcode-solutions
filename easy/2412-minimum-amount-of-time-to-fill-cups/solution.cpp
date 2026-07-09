#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        
        int max_cup = amount[2];
        int total_sum = amount[0] + amount[1] + amount[2];

        return max(max_cup, (total_sum + 1) / 2);
    }
};