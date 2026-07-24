#include <vector>
#include <bitset>

using namespace std;

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        bitset<2048> is_present;
        vector<int> unique_nums;
        unique_nums.reserve(1500); 

        for (int num : nums) {
            if (!is_present[num]) {
                is_present[num] = true;
                unique_nums.push_back(num);
            }
        }

        int u_size = unique_nums.size();

        bitset<2048> pair_xor;
        for (int i = 0; i < u_size; ++i) {
            for (int j = i; j < u_size; ++j) {
                pair_xor[unique_nums[i] ^ unique_nums[j]] = true;
            }
        }
        bitset<2048> triplet_xor;
        for (int i = 0; i < 2048; ++i) {
            if (pair_xor[i]) {
                for (int k : unique_nums) {
                    triplet_xor[i ^ k] = true;
                }
            }
        }
        return triplet_xor.count();
    }
};