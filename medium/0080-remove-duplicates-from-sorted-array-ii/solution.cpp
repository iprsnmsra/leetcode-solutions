#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n <= 2) {
            return n;
        }
        int write_index = 2;
        for (int read_index = 2; read_index < n; ++read_index) {
            if (nums[read_index] != nums[write_index - 2]) {
                nums[write_index] = nums[read_index];
                write_index++;
            }
        }
        return write_index;
    }
};