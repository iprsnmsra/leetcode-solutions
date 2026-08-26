class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int left = 0, ones = 0;
        string_view best_view;
        int min_len = n + 1; 
        for (int right = 0; right < n; ++right) {
            
            if (s[right] == '1') {
                ones++;
            }
            while (left <= right && (ones > k || s[left] == '0')) {
                if (s[left] == '1') {
                    ones--;
                }
                left++;
            }
            if (ones == k) {
                int current_len = right - left + 1;
                string_view current_view(s.data() + left, current_len);

                if (current_len < min_len) {
                    min_len = current_len;
                    best_view = current_view;
                } else if (current_len == min_len) {
                    if (current_view < best_view) {
                        best_view = current_view;
                    }
                }
            }
        }
        return string(best_view);
    }
};