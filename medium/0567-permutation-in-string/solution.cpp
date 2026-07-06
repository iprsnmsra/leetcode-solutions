class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int len1 = s1.length();
        int len2 = s2.length();
        if (len1 > len2) return false;
        vector<int> s1_map(26, 0);
        vector<int> window_map(26, 0);
        for (int i = 0; i < len1; ++i) {
            s1_map[s1[i] - 'a']++;
            window_map[s2[i] - 'a']++;
        }
        if (s1_map == window_map) return true;
        for (int i = len1; i < len2; ++i) {
            window_map[s2[i] - 'a']++;
            window_map[s2[i - len1] - 'a']--;
            if (s1_map == window_map) {
                return true;
            }
        }

        return false;
    }
};