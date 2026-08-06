class Solution {
public:
    bool isAnagram(string s, string t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (s.length() != t.length()) {
            return false;
        }
        int frequency_state[26] = {0};
        for (int i = 0; i < s.length(); ++i) {
            frequency_state[s[i] - 'a']++;
            frequency_state[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; ++i) {
            if (frequency_state[i] != 0) {
                return false;
            }
        }

        return true;
    }
};