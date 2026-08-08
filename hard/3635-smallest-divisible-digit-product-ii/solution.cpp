#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
static string dp[50][35];
static bool dp_computed[50][35];

class Solution {
    string get_min_str(int r2, int r3) {
        if (r2 <= 0 && r3 <= 0) return "";
        
        r2 = max(0, r2);
        r3 = max(0, r3);
        if (dp_computed[r2][r3]) return dp[r2][r3];
        
        string best(100, '9');
        
        int p2[] = {0,0,1,0,2,0,1,0,3,0};
        int p3[] = {0,0,0,1,0,0,1,0,0,2};
        
        for (int d = 2; d <= 9; ++d) {
            if (d == 5 || d == 7) continue; 
            bool progresses_r2 = (r2 > 0 && p2[d] > 0);
            bool progresses_r3 = (r3 > 0 && p3[d] > 0);
            if (!progresses_r2 && !progresses_r3) continue; 
            
            string cand = get_min_str(r2 - p2[d], r3 - p3[d]);
            cand += to_string(d);
            sort(cand.begin(), cand.end());
            
            if (cand.length() < best.length() || (cand.length() == best.length() && cand < best)) {
                best = cand;
            }
        }
        
        dp_computed[r2][r3] = true;
        return dp[r2][r3] = best;
    }

public:
    string smallestNumber(string num, long long t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long temp = t;
        int c2 = 0, c3 = 0, c5 = 0, c7 = 0;
        
        // Prime Factorization Phase: Extract target dimensional vectors
        while (temp % 2 == 0) { c2++; temp /= 2; }
        while (temp % 3 == 0) { c3++; temp /= 3; }
        while (temp % 5 == 0) { c5++; temp /= 5; }
        while (temp % 7 == 0) { c7++; temp /= 7; }
        if (temp > 1) return "-1";

        int n = num.length();
        int p2_map[] = {0,0,1,0,2,0,1,0,3,0};
        int p3_map[] = {0,0,0,1,0,0,1,0,0,2};
        
        vector<int> pref2(n + 1, 0), pref3(n + 1, 0), pref5(n + 1, 0), pref7(n + 1, 0);
        int first_zero = -1;
        for (int i = 0; i < n; ++i) {
            if (num[i] == '0') {
                if (first_zero == -1) first_zero = i;
                break; 
            }
            int d = num[i] - '0';
            pref2[i+1] = pref2[i] + p2_map[d];
            pref3[i+1] = pref3[i] + p3_map[d];
            pref5[i+1] = pref5[i] + (d == 5 ? 1 : 0);
            pref7[i+1] = pref7[i] + (d == 7 ? 1 : 0);
        }
        if (first_zero == -1) {
            if (pref2[n] >= c2 && pref3[n] >= c3 && pref5[n] >= c5 && pref7[n] >= c7) {
                return num;
            }
        }
        int start_i = (first_zero != -1) ? first_zero : n - 1;
        for (int i = start_i; i >= 0; --i) {
            int start_d = (num[i] - '0') + 1;
            
            for (int d = start_d; d <= 9; ++d) {
                int R2 = max(0, c2 - pref2[i] - p2_map[d]);
                int R3 = max(0, c3 - pref3[i] - p3_map[d]);
                int R5 = max(0, c5 - pref5[i] - (d == 5 ? 1 : 0));
                int R7 = max(0, c7 - pref7[i] - (d == 7 ? 1 : 0));
                string s23 = get_min_str(R2, R3);
                int req_len = s23.length() + R5 + R7;
                int spaces_left = n - 1 - i;
                if (req_len <= spaces_left) {
                    string ans = num.substr(0, i);
                    ans += to_string(d);
                    string suffix = string(spaces_left - req_len, '1'); 
                    suffix += string(R5, '5');
                    suffix += string(R7, '7');
                    suffix += s23;
                    
                    sort(suffix.begin(), suffix.end());
                    return ans + suffix;
                }
            }
        }
        string s23 = get_min_str(c2, c3);
        int req_len = s23.length() + c5 + c7;
        int final_len = max((int)n + 1, req_len);
        
        string ans = string(final_len - req_len, '1');
        ans += string(c5, '5');
        ans += string(c7, '7');
        ans += s23;
        
        sort(ans.begin(), ans.end());
        return ans;
    }
};