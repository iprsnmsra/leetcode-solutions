class Solution {
public:
    int numDecodings(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (s.empty() || s[0] == '0') {
            return 0;
        }

        int prev2 = 1; 
        int prev1 = 1; 

        for (int i = 1; i < s.length(); ++i) {
            int curr = 0;
            if (s[i] != '0') {
                curr += prev1;
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                curr += prev2;
            }
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};