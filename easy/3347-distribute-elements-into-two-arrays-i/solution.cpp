#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        vector<int> arr1;
        vector<int> arr2;
        arr1.reserve(n);
        arr2.reserve(n);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            } else {
                arr2.push_back(nums[i]);
            }
        }
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());

        return arr1;
    }
};