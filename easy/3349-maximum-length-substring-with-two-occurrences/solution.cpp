class Solution {
public:
    int maximumLengthSubstring(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int freq[26] = {0};
        
        int max_len = 0;
        int left = 0;
        for (int right = 0; right < s.length(); ++right) {

            int current_idx = s[right] - 'a';
            freq[current_idx]++;
            while (freq[current_idx] > 2) {
                int left_idx = s[left] - 'a';
                freq[left_idx]--;
                left++;
            }
            int current_window = right - left + 1;
            if (current_window > max_len) {
                max_len = current_window;
            }
        }
        
        return max_len;
    }
};