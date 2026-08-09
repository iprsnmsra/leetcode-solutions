#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string generateString(string str1, string str2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = str1.length();
        int m = str2.length();
        int len = n + m - 1;
        string ans(len, '?');
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    if (ans[i + j] != '?' && ans[i + j] != str2[j]) {
                        return "";
                    }
                    ans[i + j] = str2[j];
                }
            }
        }
        vector<int> q_count(n, 0);
        vector<int> mismatch_count(n, 0);
        
        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                for (int j = 0; j < m; ++j) {
                    if (ans[i + j] == '?') {
                        q_count[i]++;
                    } else if (ans[i + j] != str2[j]) {
                        mismatch_count[i]++;
                    }
                }
 
                if (q_count[i] == 0 && mismatch_count[i] == 0) {
                    return "";
                }
            }
        }
        
        for (int k = 0; k < len; ++k) {
            if (ans[k] == '?') {
                bool forbidden[26] = {false};
                int start_i = max(0, k - m + 1);
                int end_i = min(n - 1, k);
                
                for (int i = start_i; i <= end_i; ++i) {
                    if (str1[i] == 'F') {
                        if (mismatch_count[i] == 0 && q_count[i] == 1) {
                            forbidden[str2[k - i] - 'a'] = true;
                        }
                    }
                }
                char best = '?';
                for (int c = 0; c < 26; ++c) {
                    if (!forbidden[c]) {
                        best = 'a' + c;
                        break;
                    }
                }
                if (best == '?') return ""; 
                
                ans[k] = best;
                for (int i = start_i; i <= end_i; ++i) {
                    if (str1[i] == 'F') {
                        q_count[i]--; 
                        if (best != str2[k - i]) {
                            mismatch_count[i]++; 
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};