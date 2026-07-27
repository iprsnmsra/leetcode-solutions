#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = rooms.size();
        vector<bool> visited(n, false);

        queue<int> keys;

        visited[0] = true;
        keys.push(0);
        int visited_count = 1;

        while (!keys.empty()) {
            int current_room = keys.front();
            keys.pop();
            for (int key : rooms[current_room]) {
                if (!visited[key]) {
                    visited[key] = true; 
                    keys.push(key);     
                    visited_count++;    
                }
            }
        }
        return visited_count == n;
    }
};