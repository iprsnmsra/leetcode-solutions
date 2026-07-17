#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }
        vector<long long> count(max_val + 1, 0);
        for (int x : nums) {
            count[x]++;
        }
        vector<long long> gcd_cnt(max_val + 1, 0);
        for (int i = max_val; i >= 1; --i) {
            long long multiples = 0;
            for (int j = i; j <= max_val; j += i) {
                multiples += count[j];
            }
            long long pairs = multiples * (multiples - 1) / 2;
            for (int j = 2 * i; j <= max_val; j += i) {
                pairs -= gcd_cnt[j];
            }
            gcd_cnt[i] = pairs;
        }
        vector<long long> pref(max_val + 1, 0);
        for (int i = 1; i <= max_val; ++i) {
            pref[i] = pref[i - 1] + gcd_cnt[i];
        }
        vector<int> ans;
        ans.reserve(queries.size());

        for (long long q : queries) {
            auto it = upper_bound(pref.begin() + 1, pref.end(), q);
            ans.push_back(distance(pref.begin(), it));
        }

        return ans;
    }
};