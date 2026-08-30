#include <string>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    string getSmallestString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        for (int i = 0; i < n - 1; ++i) {
            if ((s[i] % 2) == (s[i + 1] % 2)) {
                if (s[i] > s[i + 1]) {
                    swap(s[i], s[i + 1]);
                    break;
                }
            }
        }

        return s;
    }
};