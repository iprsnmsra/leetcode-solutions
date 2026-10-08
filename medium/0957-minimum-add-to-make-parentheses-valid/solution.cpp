#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int open_count = 0;   
        int mismatch_count = 0; 
        for (char c : s) {
            if (c == '(') {
                open_count++;
            } else {
                if (open_count > 0) {
                    open_count--;
                } else {
                    mismatch_count++;
                }
            }
        }
        return open_count + mismatch_count;
    }
};