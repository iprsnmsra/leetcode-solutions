#include <string>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int ans = 0;
        int start = 0;
        auto isPalindrome = [&](int left, int right) {
            while (left < right) {
                if (s[left] != s[right]) return false;
                left++;
                right--;
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {

            if (i - start + 1 >= k && isPalindrome(i - k + 1, i)) {
                ans++;
                start = i + 1; 
                continue;
            }

            if (i - start + 1 >= k + 1 && isPalindrome(i - k, i)) {
                ans++;
                start = i + 1; 
            }
        }

        return ans;
    }
};