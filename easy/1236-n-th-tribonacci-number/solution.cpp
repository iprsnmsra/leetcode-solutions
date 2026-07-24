#include <iostream>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;


        int a = 0; 
        int b = 1; 
        int c = 1; 

        for (int i = 3; i <= n; ++i) {
            int next_val = a + b + c; 

            a = b;
            b = c;
            c = next_val;
        }
        return c;
    }
};