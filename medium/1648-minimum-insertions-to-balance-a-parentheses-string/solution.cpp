#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int req_right = 0;
        int insertions = 0;
        for (char c : s) {
            if (c == '(') {
                if (req_right % 2 != 0) {
                    req_right--;
                    insertions++;
                }
                req_right += 2;
            } else {
                req_right--;
                
                if (req_right < 0) {
                    req_right = 1;
                    insertions++;
                }
            }
        }
        return insertions + req_right;
    }
};