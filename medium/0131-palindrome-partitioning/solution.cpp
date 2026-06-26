#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();

        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start <= n - len; ++start) {
                int end = start + len - 1;
                
                if (s[start] == s[end]) {
                    if (len <= 2 || dp[start + 1][end - 1]) {
                        dp[start][end] = true;
                    }
                }
            }
        }
        
        vector<vector<string>> result;
        vector<string> current_path;
        dfs(s, 0, dp, current_path, result);
        
        return result;
    }

private:
    void dfs(const string& s, int start, const vector<vector<bool>>& dp, 
             vector<string>& current_path, vector<vector<string>>& result) {
        if (start == s.length()) {
            result.push_back(current_path);
            return;
        }
        for (int end = start; end < s.length(); ++end) {

            if (dp[start][end]) {
                current_path.push_back(s.substr(start, end - start + 1));

                dfs(s, end + 1, dp, current_path, result);

                current_path.pop_back();
            }
        }
    }
};