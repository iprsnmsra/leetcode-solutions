#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;
struct Item {
    int price;
    int r;
    int c;
    
    // Custom comparator: Price -> Row -> Col
    bool operator<(const Item& other) const {
        if (price != other.price) return price < other.price;
        if (r != other.r) return r < other.r;
        return c < other.c;
    }
};

class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>>& grid, vector<int>& pricing, vector<int>& start, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = grid.size();
        int n = grid[0].size();
        int low = pricing[0];
        int high = pricing[1];

        vector<vector<int>> result;
        vector<bool> visited(m * n, false);
        queue<pair<int, int>> q;

        
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        q.push({start[0], start[1]});
        visited[start[0] * n + start[1]] = true;

        // BFS Loop
        while (!q.empty() && result.size() < k) {
            int level_size = q.size();
            vector<Item> layer_items;

            // Process all cells at the current distance layer
            for (int i = 0; i < level_size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                int price = grid[r][c];
                
                
                if (price >= low && price <= high) {
                    layer_items.push_back({price, r, c});
                }

                // Explore neighbors
                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
                        if (grid[nr][nc] > 0 && !visited[nr * n + nc]) {
                            visited[nr * n + nc] = true;
                            q.push({nr, nc});
                        }
                    }
                }
            }

         
            sort(layer_items.begin(), layer_items.end());
            for (const auto& item : layer_items) {
                result.push_back({item.r, item.c});
                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};