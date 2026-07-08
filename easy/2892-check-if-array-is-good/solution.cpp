#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size() - 1;

        if (n < 1) return false;

        vector<int> freq(n + 1, 0);
        
        for (int num : nums) {

            if (num > n || num < 1) {
                return false;
            }
            freq[num]++;
        }

        for (int i = 1; i < n; ++i) {
            if (freq[i] != 1) {
                return false;
            }
        }
        return freq[n] == 2;
    }
};