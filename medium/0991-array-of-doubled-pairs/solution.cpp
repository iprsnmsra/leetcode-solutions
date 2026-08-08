#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        const int OFFSET = 100000;
        const int MAX_VAL = 100000;
        vector<int> freq(200005, 0);
        for (const int& num : arr) {
            freq[num + OFFSET]++;
        }
        if (freq[OFFSET] % 2 != 0) {
            return false;
        }
        for (int i = 1; i <= MAX_VAL; ++i) {
            if (freq[i + OFFSET] > 0) {
                if (2 * i > MAX_VAL) return false;
                if (freq[2 * i + OFFSET] < freq[i + OFFSET]) return false; 
                freq[2 * i + OFFSET] -= freq[i + OFFSET];
            }
        }
        for (int i = -1; i >= -MAX_VAL; --i) {
            if (freq[i + OFFSET] > 0) {
                if (2 * i < -MAX_VAL) return false; 
                if (freq[2 * i + OFFSET] < freq[i + OFFSET]) return false; 
                
                freq[2 * i + OFFSET] -= freq[i + OFFSET];
            }
        }

        return true;
    }
};