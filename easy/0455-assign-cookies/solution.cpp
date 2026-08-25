#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int child_i = 0;
        int cookie_j = 0;
        while (child_i < g.size() && cookie_j < s.size()) {
            if (s[cookie_j] >= g[child_i]) {
                child_i++;
            }
            cookie_j++; 
        }
        return child_i;
    }
};