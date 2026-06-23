#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> last_occurrence(26, 0);
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            last_occurrence[s[i] - 'a'] = i;
        }

        vector<int> partitions;
        int current_start = 0;
        int current_end = 0;

        for (int i = 0; i < n; ++i) {

            current_end = max(current_end, last_occurrence[s[i] - 'a']);

            if (i == current_end) {
                partitions.push_back(current_end - current_start + 1);

                current_start = i + 1;
            }
        }

        return partitions;
    }
};