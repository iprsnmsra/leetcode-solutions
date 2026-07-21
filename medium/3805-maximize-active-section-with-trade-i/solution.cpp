#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int base_ones = 0;
        for (char c : s) {
            if (c == '1') base_ones++;
        }
        string t = "1" + s + "1";
        vector<pair<char, int>> groups;
        int count = 1;
        for (int i = 1; i < t.length(); ++i) {
            if (t[i] == t[i - 1]) {
                count++;
            } else {
                groups.push_back({t[i - 1], count});
                count = 1;
            }
        }
        groups.push_back({t.back(), count});
        vector<int> Z;
        for (const auto& g : groups) {
            if (g.first == '0') {
                Z.push_back(g.second);
            }
        }

        int m = Z.size();
        if (m <= 1) return base_ones;
        vector<int> pref(m), suff(m);
        pref[0] = Z[0];
        for (int i = 1; i < m; ++i) {
            pref[i] = max(pref[i - 1], Z[i]);
        }
        
        suff[m - 1] = Z[m - 1];
        for (int i = m - 2; i >= 0; --i) {
            suff[i] = max(suff[i + 1], Z[i]);
        }

        int best_gain = 0; 
        for (int i = 1; i < m; ++i) {
            int len1 = groups[2 * i].second; 
            int z_left = Z[i - 1];
            int z_right = Z[i];
            int other_max = 0;
            if (i - 2 >= 0) other_max = max(other_max, pref[i - 2]);
            if (i + 1 < m)  other_max = max(other_max, suff[i + 1]);
            int gain = max(z_left + z_right, other_max - len1);
            best_gain = max(best_gain, gain);
        }

        return base_ones + best_gain;
    }
};