#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool sumGame(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = num.length();
        int sum_L = 0, sum_R = 0;
        int q_L = 0, q_R = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') q_L++;
            else sum_L += num[i] - '0';
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') q_R++;
            else sum_R += num[i] - '0';
        }
        if ((q_L + q_R) % 2 != 0) return true;
        return (sum_L - sum_R) * 2 != (q_R - q_L) * 9;
    }
};