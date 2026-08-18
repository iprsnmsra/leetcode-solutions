#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_cost = 0;
        int r_step = (startPos[0] < homePos[0]) ? 1 : -1;
        
        for (int r = startPos[0]; r != homePos[0]; ) {
            r += r_step; 
            total_cost += rowCosts[r];
        }
        int c_step = (startPos[1] < homePos[1]) ? 1 : -1;
        
        for (int c = startPos[1]; c != homePos[1]; ) {
            c += c_step; 
            total_cost += colCosts[c];
        }

        return total_cost;
    }
};