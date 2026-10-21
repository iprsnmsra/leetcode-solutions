#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += (nums[i - 1] * nums[i - 1]) * (n % i == 0);
            
        }

        return sum;
    }
};