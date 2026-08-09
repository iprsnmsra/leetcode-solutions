#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = positions.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0); 

        sort(ids.begin(), ids.end(), [&](int i, int j) {
            return positions[i] < positions[j];
        });

        vector<int> stack; 
        for (int id : ids) {
            if (directions[id] == 'R') {
                stack.push_back(id);
            } else {
                while (!stack.empty() && healths[id] > 0) {
                    int top_id = stack.back();
                    
                    if (healths[id] > healths[top_id]) {
                        
                        healths[top_id] = 0; 
                        stack.pop_back();
                        healths[id] -= 1; 
                    } else if (healths[id] < healths[top_id]) {
                        healths[id] = 0; 
                        healths[top_id] -= 1; 
                        break; 
                    } else {
                        
                        healths[id] = 0;
                        healths[top_id] = 0;
                        stack.pop_back();
                        break; 
                    }
                }
            }
        }
        vector<int> result;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                result.push_back(healths[i]);
            }
        }

        return result;
    }
};