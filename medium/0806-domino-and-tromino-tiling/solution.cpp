#include <iostream>

using namespace std;

class Solution {
public:
    int numTilings(int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (n <= 2) return n;

        long long MOD = 1e9 + 7;

        long long prev3 = 1; 
        long long prev2 = 1; 
        long long prev1 = 2; 

        for (int i = 3; i <= n; ++i) {
            long long curr = (2 * prev1 + prev3) % MOD;
            
            prev3 = prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};