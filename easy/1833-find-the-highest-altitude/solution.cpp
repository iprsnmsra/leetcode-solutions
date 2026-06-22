#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int current_altitude = 0;
        int max_altitude = 0; 
        for (int g : gain) {
            current_altitude += g; 
            if (current_altitude > max_altitude) {
                max_altitude = current_altitude;
            }
        }

        return max_altitude;
    }
};