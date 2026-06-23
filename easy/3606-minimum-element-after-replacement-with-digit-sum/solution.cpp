#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    int minElement(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int min_element = INT_MAX;

        for (int num : nums) {
            int current_sum = 0;

            while (num > 0) {
                current_sum += num % 10; 
                num /= 10;             
            }

            if (current_sum < min_element) {
                min_element = current_sum;
            }
        }

        return min_element;
    }
};