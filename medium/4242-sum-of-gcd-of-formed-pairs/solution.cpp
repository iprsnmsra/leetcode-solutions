#include <vector>
#include <numeric>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> prefixGcd(n);
        int current_max = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > current_max) {
                current_max = nums[i];
            }
            prefixGcd[i] = std::gcd(nums[i], current_max);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long sum = 0;
        int left = 0;
        int right = n - 1;
        while (left < right) {
            sum += std::gcd(prefixGcd[left], prefixGcd[right]);
            left++;
            right--;
        }

        return sum;
    }
};