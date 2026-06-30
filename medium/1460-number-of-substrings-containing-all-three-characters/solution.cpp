#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int last_seen[3] = {-1, -1, -1};
        int count = 0;

        for (int i = 0; i < s.length(); ++i) {
            last_seen[s[i] - 'a'] = i;
            int min_idx = min(last_seen[0], min(last_seen[1], last_seen[2]));
            if (min_idx != -1) {
                count += (min_idx + 1);
            }
        }

        return count;
    }
};