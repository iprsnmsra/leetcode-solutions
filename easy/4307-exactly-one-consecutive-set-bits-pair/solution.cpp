#include <bit>

class Solution {
public:
    bool consecutiveSetBits(int n) {
        return std::has_single_bit(static_cast<unsigned int>(n & (n >> 1)));
    }
};