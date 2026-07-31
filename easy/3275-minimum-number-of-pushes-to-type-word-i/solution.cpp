#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minimumPushes(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = word.length();
        int total_pushes = 0;
        for (int i = 0; i < n; ++i) {
            total_pushes += (i >> 3) + 1;
        }

        return total_pushes;
    }
};