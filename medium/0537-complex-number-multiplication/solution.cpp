#include <string>
#include <cstdio> 

using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int r1, i1, r2, i2;

        sscanf(num1.c_str(), "%d+%di", &r1, &i1);
        sscanf(num2.c_str(), "%d+%di", &r2, &i2);
        
        int real_res = (r1 * r2) - (i1 * i2);
        int imag_res = (r1 * i2) + (i1 * r2);

        return to_string(real_res) + "+" + to_string(imag_res) + "i";
    }
};