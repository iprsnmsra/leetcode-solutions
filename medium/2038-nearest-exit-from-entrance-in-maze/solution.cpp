#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size();
        int cols = maze[0].size();
        queue<pair<pair<int, int>, int>> q;
        q.push({{entrance[0], entrance[1]}, 0});

        maze[entrance[0]][entrance[1]] = '+';
        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        
        while (!q.size() == 0) {
            auto curr = q.front();
            q.pop();
            
            int r = curr.first.first;
            int c = curr.first.second;
            int d = curr.second;
            if (d > 0 && (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)) {
                return d;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && maze[nr][nc] == '.') {
                    maze[nr][nc] = '+';
                    q.push({{nr, nc}, d + 1});
                }
            }
        }
        
        return -1; 
    }
};