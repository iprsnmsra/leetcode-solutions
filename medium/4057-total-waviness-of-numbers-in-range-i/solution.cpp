#include <iostream>

using namespace std;

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_waviness = 0;

        for (int i = num1; i <= num2; ++i) {
            int temp = i;

            if (temp < 100) continue; 

            int right = temp % 10; 
            temp /= 10;
            
            int mid = temp % 10; 
            temp /= 10;

            while (temp > 0) {
                int left = temp % 10; 
                temp /= 10;

                if (mid > left && mid > right) {
                    total_waviness++;
                } 

                else if (mid < left && mid < right) {
                    total_waviness++;
                }

                right = mid;
                mid = left;
            }
        }

        return total_waviness;
    }
};