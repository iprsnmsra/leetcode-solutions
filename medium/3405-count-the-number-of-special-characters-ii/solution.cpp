#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int numberOfSpecialChars(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> state(26, 0);
        for (char c : word) {
            if (c >= 'a' && c <= 'z') {
                int idx = c - 'a';
                if (state[idx] == 0) {
                    state[idx] = 1; 
                } else if (state[idx] == 2) {
                    state[idx] = -1; 
                }
            } else {
                int idx = c - 'A';
                if (state[idx] == 0) {
                    state[idx] = -1;
                } else if (state[idx] == 1) {
                    state[idx] = 2;
                }
            }
        }

        int special_count = 0;
        for (int s : state) {
            if (s == 2) {
                special_count++;
            }
        }

        return special_count;
    }
};