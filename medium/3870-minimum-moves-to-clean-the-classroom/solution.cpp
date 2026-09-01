#include <vector>
#include <string>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
struct State {
    int r, c, e, mask, dist;
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = classroom.size();
        int n = classroom[0].size();
        int litter_id[20][20];
        memset(litter_id, -1, sizeof(litter_id));
        
        int start_r = -1, start_c = -1;
        int num_litter = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    start_r = r;
                    start_c = c;
                } else if (classroom[r][c] == 'L') {
                    litter_id[r][c] = num_litter++;
                }
            }
        }
        int target_mask = (1 << num_litter) - 1;
        if (target_mask == 0) return 0;
        int max_energy[20][20][1024];
        memset(max_energy, -1, sizeof(max_energy));
        
        queue<State> q;
        q.push({start_r, start_c, energy, 0, 0});
        max_energy[start_r][start_c][0] = energy;
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            State curr = q.front();
            q.pop();
            if (curr.mask == target_mask) {
                return curr.dist;
            }
            if (curr.e == 0) continue;
            
            for (int i = 0; i < 4; ++i) {
                int nr = curr.r + dr[i];
                int nc = curr.c + dc[i];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                    int next_e = curr.e - 1;
                    if (next_e < 0) continue;
                    
                    int next_mask = curr.mask;
                    if (classroom[nr][nc] == 'L') {
                        next_mask |= (1 << litter_id[nr][nc]);
                    }
                    if (classroom[nr][nc] == 'R') {
                        next_e = energy;
                    }
                    if (next_e > max_energy[nr][nc][next_mask]) {
                        max_energy[nr][nc][next_mask] = next_e;
                        q.push({nr, nc, next_e, next_mask, curr.dist + 1});
                    }
                }
            }
        }
        
        return -1; 
    }
};