#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long wonderfulSubstrings(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long count[1024] = {0}; 

        count[0] = 1; 

        long long total_wonderful = 0;
        int mask = 0;

        for (char c : word) {
            int bit_index = c - 'a';
            mask ^= (1 << bit_index);

            total_wonderful += count[mask];
            for (int k = 0; k < 10; ++k) {
                int flipped_mask = mask ^ (1 << k);
                total_wonderful += count[flipped_mask];
            }
            count[mask]++;
        }

        return total_wonderful;
    }
}; 