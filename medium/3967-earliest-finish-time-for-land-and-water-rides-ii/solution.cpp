#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
    long long getMinFinishTime(const vector<int>& startA, const vector<int>& durA,
                               const vector<int>& startB, const vector<int>& durB) {
        
        int n = startA.size();
        int m = startB.size();

        vector<pair<long long, long long>> B(m);
        for (int i = 0; i < m; ++i) {
            B[i] = {startB[i], durB[i]};
        }
        sort(B.begin(), B.end());

        vector<long long> pref_min_dur(m);
        pref_min_dur[0] = B[0].second;
        for (int i = 1; i < m; ++i) {
            pref_min_dur[i] = min(pref_min_dur[i - 1], B[i].second);
        }

        vector<long long> suff_min_end(m);
        suff_min_end[m - 1] = B[m - 1].first + B[m - 1].second;
        for (int i = m - 2; i >= 0; --i) {
            suff_min_end[i] = min(suff_min_end[i + 1], B[i].first + B[i].second);
        }

        vector<long long> b_starts(m);
        for (int i = 0; i < m; ++i) {
            b_starts[i] = B[i].first;
        }

        long long global_min = LLONG_MAX;

        for (int i = 0; i < n; ++i) {
            long long a_end = (long long)startA[i] + durA[i];

            auto it = upper_bound(b_starts.begin(), b_starts.end(), a_end);
            int idx = distance(b_starts.begin(), it);

            long long best_for_a = LLONG_MAX;

            if (idx > 0) {
                best_for_a = min(best_for_a, a_end + pref_min_dur[idx - 1]);
            }

            if (idx < m) {
                best_for_a = min(best_for_a, suff_min_end[idx]);
            }

            global_min = min(global_min, best_for_a);
        }

        return global_min;
    }

public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, 
                           vector<int>& waterStartTime, vector<int>& waterDuration) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long route1 = getMinFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
        long long route2 = getMinFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

        return min(route1, route2);
    }
};