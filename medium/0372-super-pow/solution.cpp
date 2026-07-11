#include <vector>

using namespace std;

class Solution {
private:
    const int MOD = 1337;

    int pow_mod(int x, int n) {
        int res = 1;
        x %= MOD; 
        for (int i = 0; i < n; ++i) {
            res = (res * x) % MOD;
        }
        return res;
    }

public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;

        int last_digit = b.back();
        b.pop_back();

        int prefix_result = superPow(a, b);

        int part1 = pow_mod(prefix_result, 10);
        int part2 = pow_mod(a, last_digit);
        return (part1 * part2) % MOD;
    }
};