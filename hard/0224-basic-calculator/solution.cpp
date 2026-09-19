class Solution {
public:
    int calculate(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        vector<int> ctx;
        ctx.reserve(n);
        ctx.push_back(1);
        
        int curr_sign = 1;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            
            if (c >= '0' && c <= '9') {
                long long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                ans += curr_sign * num;
                i--; 
                
            } else if (c == '+') {
                curr_sign = ctx.back();
            } else if (c == '-') {
                curr_sign = -ctx.back();
            } else if (c == '(') {
                ctx.push_back(curr_sign);
            } else if (c == ')') {
                ctx.pop_back();
            }
        }
        
        return ans;
    }
};