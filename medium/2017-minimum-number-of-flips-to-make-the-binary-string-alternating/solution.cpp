#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minFlips(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int diff1 = 0, diff2 = 0;
        int min_ops = n; 
        for (int i = 0; i < 2 * n; ++i) {
            char c = s[i % n];
            char expected1 = (i % 2 == 0) ? '0' : '1'; 
            char expected2 = (i % 2 == 0) ? '1' : '0'; 
            if (c != expected1) diff1++;
            if (c != expected2) diff2++;
            if (i >= n) {
                int left_idx = i - n;
                char left_c = s[left_idx % n];
                
                char left_expected1 = (left_idx % 2 == 0) ? '0' : '1';
                char left_expected2 = (left_idx % 2 == 0) ? '1' : '0';
                if (left_c != left_expected1) diff1--;
                if (left_c != left_expected2) diff2--;
            }
            if (i >= n - 1) {
                min_ops = min({min_ops, diff1, diff2});
            }
        }

        return min_ops;
    }
};