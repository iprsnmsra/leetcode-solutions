#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        vector<long long> L(n, 0);
        long long cur_len = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                cur_len++;
            } 
            else if (s[i] == '*') {
                cur_len = max(0LL, cur_len - 1);
            } 
            else if (s[i] == '#') {
                cur_len *= 2;
            } 
            
            L[i] = cur_len;
        }
        if (k >= L[n - 1] || k < 0) {
            return '.';
        }
        long long curr_k = k;
        
        for (int i = n - 1; i >= 0; --i) {
            long long prev_len = (i == 0) ? 0 : L[i - 1];

            if (s[i] >= 'a' && s[i] <= 'z') {
                if (curr_k == prev_len) {
                    return s[i];
                }
            } 
            else if (s[i] == '*') {

            } 
            else if (s[i] == '#') {
                if (curr_k >= prev_len) {
                    curr_k -= prev_len;
                }
            } 
            else if (s[i] == '%') {
                curr_k = prev_len - 1 - curr_k;
            }
        }

        return '.';
    }
};