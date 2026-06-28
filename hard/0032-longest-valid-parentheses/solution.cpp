#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
     
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int left = 0, right = 0, maxlength = 0;
        int n = s.length();

 
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
               
                maxlength = max(maxlength, 2 * right);
            } else if (right > left) {
                
                left = right = 0;
            }
        }
        left = right = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '(') {
                left++;
            } else {
                right++;
            }
            
            if (left == right) {
   
                maxlength = max(maxlength, 2 * left);
            } else if (left > right) {

                left = right = 0;
            }
        }

        return maxlength;
    }
};