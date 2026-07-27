#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = isConnected.size();

        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        int provinces = n;

        auto find = [&](auto& self, int i) -> int {
            if (parent[i] == i) {
                return i;
            }

            return parent[i] = self(self, parent[i]);
        };
        for (int i = 0; i < n; ++i) {

            for (int j = i + 1; j < n; ++j) {
                if (isConnected[i][j] == 1) {
                    int rootI = find(find, i);
                    int rootJ = find(find, j);
                    if (rootI != rootJ) {
                        parent[rootI] = rootJ; 
                        provinces--;          
                    }
                }
            }
        }

        return provinces;
    }
};