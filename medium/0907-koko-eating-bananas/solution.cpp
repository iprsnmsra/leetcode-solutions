#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 1;
        int right = 0;

        for (int pile : piles) {
            if (pile > right) {
                right = pile;
            }
        }

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (canEatAll(piles, mid, h)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

private:
    bool canEatAll(const vector<int>& piles, int speed, int h) {
        long long hours_needed = 0;
        
        for (int pile : piles) {
            hours_needed += (pile + speed - 1) / speed;

            if (hours_needed > h) {
                return false;
            }
        }
        
        return hours_needed <= h;
    }
};