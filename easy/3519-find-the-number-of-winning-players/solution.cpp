#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> counts(n, vector<int>(11, 0));

        for (const auto& p : pick) {
            counts[p[0]][p[1]]++;
        }
        
        int winners = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int color = 0; color <= 10; ++color) {
                if (counts[i][color] > i) {
                    winners++;
                    break;
                }
            }
        }
        
        return winners;
    }
};