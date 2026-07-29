class Solution {
public:
    string smallestPalindrome(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }
        vector<int> F(26, 0);
        char odd_char = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                odd_char = 'a' + i;
            }
            F[i] = count[i] / 2;
        }

        int half_len = n / 2;
        vector<vector<int>> C(half_len + 1);
        for (int i = 0; i <= half_len; ++i) {
            C[i].resize(i + 1, 0);
            C[i][0] = 1;
            C[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                long long val = (long long)C[i - 1][j - 1] + C[i - 1][j];
                C[i][j] = (val > 1000000) ? 1000001 : val;
            }
        }
        auto get_ways = [&](vector<int>& current_F) -> long long {
            long long ways = 1;
            int sum = 0;
            for (int i = 0; i < 26; ++i) {
                if (current_F[i] == 0) continue;
                sum += current_F[i];
                ways = ways * C[sum][current_F[i]];
                if (ways > 1000000) return 1000001; 
            }
            return ways;
        };
        if (k > get_ways(F)) {
            return "";
        }

        string left_half = "";
        left_half.reserve(half_len);
        for (int pos = 0; pos < half_len; ++pos) {
            for (int c = 0; c < 26; ++c) {
                if (F[c] > 0) {
                    F[c]--; 
                    
                    long long ways = get_ways(F);
                    
                    if (k <= ways) {
                        left_half += (char)('a' + c);
                        break;
                    } else {
                        k -= ways;
                        F[c]++; 
                    }
                }
            }
        }
        string right_half = left_half;
        reverse(right_half.begin(), right_half.end());

        string ans = left_half;
        if (odd_char != 0) ans += odd_char;
        ans += right_half;

        return ans;
    }
};