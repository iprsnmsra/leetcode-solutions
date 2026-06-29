#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int count = 0;
        for (const string& pattern : patterns) {
            if (word.find(pattern) != string::npos) {
                count++;
            }
        }

        return count;
    }
};