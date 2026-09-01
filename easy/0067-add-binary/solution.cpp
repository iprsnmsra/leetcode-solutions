#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        res.reserve(max(a.length(), b.length()) + 1);
        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
        
            if (i >= 0) {
                sum += (a[i] - '0'); 
                i--;
            }
            
           
            if (j >= 0) {
                sum += (b[j] - '0');
                j--;
            }

            res += to_string(sum % 2);
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        
        return res;
    }
};