#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> counts(value, 0);

        for (int x : nums) {

            int rem = ((x % value) + value) % value;
            counts[rem]++;
        }

        int mex = 0;
        while (true) {
            int needed_bucket = mex % value;
            
            if (counts[needed_bucket] > 0) {
                counts[needed_bucket]--;
                mex++;
            } else {
                break;
            }
        }
        
        return mex;
    }
};