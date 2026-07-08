class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = s.length();
        long long MOD = 1e9 + 7;
        vector<int> count(m, 0);
        vector<long long> pref_sum(m, 0);
        vector<long long> P(m + 1, 0);
        vector<long long> pow10(m + 1, 1);
        for (int i = 1; i <= m; ++i) {
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        }

        int non_zero_count = 0;
        long long current_sum = 0;
        for (int i = 0; i < m; ++i) {
            int digit = s[i] - '0';
            
            if (digit != 0) {
                non_zero_count++;
                P[non_zero_count] = (P[non_zero_count - 1] * 10 + digit) % MOD;
            }
            current_sum += digit;
            count[i] = non_zero_count;
            pref_sum[i] = current_sum;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (const auto& q : queries) {
            int L = q[0];
            int R = q[1];
            int v = count[R];
            int u = (L == 0) ? 0 : count[L - 1];
            int k = v - u; 

            if (k == 0) {
                ans.push_back(0);
                continue;
            }
            long long sum = pref_sum[R] - ((L == 0) ? 0 : pref_sum[L - 1]);
            sum %= MOD; 
            long long x_subtracted = (P[u] * pow10[k]) % MOD;
            long long x = (P[v] - x_subtracted + MOD) % MOD;
            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};