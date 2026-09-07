#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long mod = 1e9 + 7;
        long long last_added[26] = {0};
        
        long long total = 0;
        for (char c : s) {
            int idx = c - 'a';
            long long new_added = (total + 1) % mod;
            total = (total + new_added - last_added[idx] + mod) % mod;
            last_added[idx] = new_added;
        }

        return total;
    }
};