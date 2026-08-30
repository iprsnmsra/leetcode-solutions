#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_operations = 0;
        int divisor = 2;
        while (n > 1) {
            while (n % divisor == 0) {
                total_operations += divisor; 
                n /= divisor;              
            }
            divisor++;
        }

        return total_operations;
    }
};