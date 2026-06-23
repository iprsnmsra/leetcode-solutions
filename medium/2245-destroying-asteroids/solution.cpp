#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(asteroids.begin(), asteroids.end());

        long long current_mass = mass;

        for (int asteroid : asteroids) {
            if (current_mass >= asteroid) {
                current_mass += asteroid;
            } else {
            
                return false;
            }
        }

        return true;
    }
};