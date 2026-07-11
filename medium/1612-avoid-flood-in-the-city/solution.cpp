#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = rains.size();
        vector<int> ans(n, 1); 
        
        unordered_map<int, int> full_lakes; 
        set<int> dry_days; 

        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) {
                dry_days.insert(i);
            } else {
                int lake = rains[i];
                ans[i] = -1; 

                if (full_lakes.count(lake)) {
                    auto it = dry_days.lower_bound(full_lakes[lake]);
                    
                    if (it == dry_days.end()) {
                        return {}; 
                    }
                    int dry_day_index = *it;
                    ans[dry_day_index] = lake;
                    dry_days.erase(it); 
                }
                full_lakes[lake] = i;
            }
        }

        return ans;
    }
};