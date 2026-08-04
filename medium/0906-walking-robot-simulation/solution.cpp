#include <vector>
#include <unordered_set>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_set<long long> obs_set;
        for (const auto& obs : obstacles) {
            long long encoded = (long long)(obs[0] + 30000) * 100000LL + (obs[1] + 30000);
            obs_set.insert(encoded);
        }
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        int x = 0;
        int y = 0;
        int dir = 0; 
        
        int max_dist_sq = 0;
        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } 
            else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } 
            else {
                for (int step = 0; step < cmd; ++step) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    long long next_encoded = (long long)(nx + 30000) * 100000LL + (ny + 30000);
                    
                    if (obs_set.count(next_encoded)) {
                        break; 
                    }
                    x = nx;
                    y = ny;
                    max_dist_sq = max(max_dist_sq, x * x + y * y);
                }
            }
        }

        return max_dist_sq;
    }
};