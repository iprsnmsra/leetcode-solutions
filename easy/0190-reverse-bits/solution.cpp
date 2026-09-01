#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        for (int i = 0; i < 32; i++) {
        
            result = result << 1;
            if (n & 1) {
                result++; // or result = result | 1;
            }
            n = n >> 1;
        }
        
        return result;
    }
};