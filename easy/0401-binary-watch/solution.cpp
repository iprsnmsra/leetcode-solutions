#include <vector>
#include <string>
#include <iostream>
#include <bitset>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        
        // Iterate through all possible hours (0-11)
        for (int h = 0; h < 12; h++) {
            // Iterate through all possible minutes (0-59)
            for (int m = 0; m < 60; m++) {
                
                // Check if the total number of set bits matches turnedOn
                // __builtin_popcount is a GCC/Clang intrinsic for counting set bits efficiently
                // In standard C++20, you can use std::popcount
                // For interviews, bitset<>.count() is also standard and safe.
                
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    string time = to_string(h) + ":";
                    
                    if (m < 10) {
                        time += "0";
                    }
                    time += to_string(m);
                    
                    result.push_back(time);
                }
            }
        }
        
        return result;
    }
};