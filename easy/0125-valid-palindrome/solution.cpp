class Solution {
    inline bool isAlphanumeric(char c) {
        return (c >= 'A' && c <= 'Z') || 
               (c >= 'a' && c <= 'z') || 
               (c >= '0' && c <= '9');
    }

    inline char toLower(char c) {
        if (c >= 'A' && c <= 'Z') return c | 0x20;
        return c;
    }

public:
    bool isPalindrome(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 0;
        int right = s.length();
        while (left < right) {
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }
            if (toLower(s[left]) != toLower(s[right])) {
                return false; 
            }
            left++;
            right--;
        }
        return true;
    }
};