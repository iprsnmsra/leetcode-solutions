#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int x = 0;
        int y = 0;

        for (char move : moves) {
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'R') {
                x++;
            } else if (move == 'L') {
                x--;
            }
        }

        return x == 0 && y == 0;
    }
};