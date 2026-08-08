#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> stack;

        for (int a : asteroids) {
            if (a > 0) {
                stack.push_back(a);
            } else {
                while (!stack.empty() && stack.back() > 0 && stack.back() < abs(a)) {
                    stack.pop_back(); 
                }
                if (stack.empty() || stack.back() < 0) {
                    stack.push_back(a);
                } else if (stack.back() == abs(a)) {
                    stack.pop_back();
                }

            }
        }

        return stack;
    }
};