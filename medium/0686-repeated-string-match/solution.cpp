#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_repeats = 1;
        string repeated_a = a;
        int max_len = b.length() + (a.length() * 2);
        repeated_a.reserve(max_len);
        while (repeated_a.length() < b.length()) {
            repeated_a += a;
            min_repeats++;
        }
        if (repeated_a.find(b) != string::npos) {
            return min_repeats;
        }
        repeated_a += a;
        if (repeated_a.find(b) != string::npos) {
            return min_repeats + 1;
        }
        return -1;
    }
};