#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        string result = "";
        result.reserve(n);
        for (int i = 0; i < n; ++i) {
       
            if (nums[i][i] == '0') {
                result += '1';
            } else {
                result += '0';
            }
        }

        return result;
    }
};