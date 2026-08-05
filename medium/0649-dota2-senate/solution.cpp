#include <string>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = senate.length();
        queue<int> radiant;
        queue<int> dire;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int r_idx = radiant.front();
            int d_idx = dire.front();
            
            radiant.pop();
            dire.pop();
            if (r_idx < d_idx) {
                radiant.push(r_idx + n);
            } else {
                dire.push(d_idx + n);
            }
        }
        return radiant.empty() ? "Dire" : "Radiant";
    }
};