#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n1 = word1.length();
        int n2 = word2.length();
        
        string merged;
        merged.reserve(n1 + n2);
        
        int i = 0;
        while (i < n1 && i < n2) {
            merged += word1[i];
            merged += word2[i];
            i++;
        }
        if (i < n1) {
            merged += word1.substr(i);
        } else if (i < n2) {
            merged += word2.substr(i);
        }
        
        return merged;
    }
};