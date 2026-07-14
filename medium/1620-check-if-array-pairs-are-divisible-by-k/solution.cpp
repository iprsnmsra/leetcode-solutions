#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> freq(k, 0);
        for (int num : arr) {
            int rem = ((num % k) + k) % k;
            freq[rem]++;
        }
        if (freq[0] % 2 != 0) {
            return false;
        }
        for (int i = 1; i <= k / 2; ++i) {
            if (i == k - i) {
                if (freq[i] % 2 != 0) {
                    return false;
                }
            } 
            else {
                if (freq[i] != freq[k - i]) {
                    return false;
                }
            }
        }

        return true;
    }
};