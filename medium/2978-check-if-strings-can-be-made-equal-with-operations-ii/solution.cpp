#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkStrings(string s1, string s2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<int> even_count(26, 0);
        vector<int> odd_count(26, 0);

        int n = s1.length();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                even_count[s1[i] - 'a']++;
                even_count[s2[i] - 'a']--;
            } else {
                odd_count[s1[i] - 'a']++;
                odd_count[s2[i] - 'a']--;
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (even_count[i] != 0 || odd_count[i] != 0) {
                return false;
            }
        }

        return true;
    }
};