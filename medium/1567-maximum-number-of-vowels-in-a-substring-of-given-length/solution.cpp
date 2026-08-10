#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    inline int isVowel(char c) {
        switch(c) {
            case 'a': case 'e': case 'i': case 'o': case 'u': 
                return 1;
            default: 
                return 0;
        }
    }

public:
    int maxVowels(string s, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = s.length();
        int current_vowels = 0;
        int max_vowels = 0;
        for (int i = 0; i < k; ++i) {
            current_vowels += isVowel(s[i]);
        }
        
        max_vowels = current_vowels;
        if (max_vowels == k) return k;
        for (int i = k; i < n; ++i) {
            current_vowels += isVowel(s[i]) - isVowel(s[i - k]);
            
            if (current_vowels > max_vowels) {
                max_vowels = current_vowels;
                if (max_vowels == k) return k;
            }
        }

        return max_vowels;
    }
};