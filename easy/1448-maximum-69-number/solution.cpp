#include <iostream>

using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int temp = num;
        int multiplier = 1;
        int six_position = -1;
        while (temp > 0) {
          
            if (temp % 10 == 6) {
                six_position = multiplier; 
            }
            
            temp /= 10;        
            multiplier *= 10;  
        }
        if (six_position != -1) {
            num += 3 * six_position;
        }

        return num;
    }
};