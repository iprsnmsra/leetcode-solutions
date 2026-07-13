#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> res;
        res.reserve(nums.size() * 6);

        for (int n : nums) {
            int div = 1;
            while (div <= n / 10) {
                div *= 10;
            }

            while (div > 0) {
                res.push_back((n / div) % 10);
                div /= 10; 
            }
        }

        return res;
    }
};