#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:

    int longestBalanced(vector<int>& nums) {
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int max_len = 0;

        static int last_seen_at[100001];
   
        fill(begin(last_seen_at), end(last_seen_at), -1);

        for (int i = 0; i < n; ++i) {
            int evens = 0;
            int odds = 0;

            for (int j = i; j < n; ++j) {
                int val = nums[j];

                
                if (last_seen_at[val] != i) {
                    last_seen_at[val] = i;
                    
                    if (val % 2 == 0) {
                        evens++;
                    } else {
                        odds++;
                    }
                }

                
                if (evens == odds) {
                    max_len = max(max_len, j - i + 1);
                }
            }
        }

        return max_len;
    }
};