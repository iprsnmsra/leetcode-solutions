#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int closest_x = clamp(xCenter, x1, x2);
        int closest_y = clamp(yCenter, y1, y2);
        int dx = xCenter - closest_x;
        int dy = yCenter - closest_y;
        return (dx * dx) + (dy * dy) <= (radius * radius);
    }
};