#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> result;
        sort(potions.begin(), potions.end());
        
        for (int s : spells) {
            long long min_potion_needed = (success + s - 1) / s; 

            auto it = lower_bound(potions.begin(), potions.end(), min_potion_needed);
            
            int count = potions.end() - it;
            result.push_back(count);
        }
        
        return result;
    }
};