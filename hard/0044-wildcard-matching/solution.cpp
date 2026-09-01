#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0; // Pointer for string s
        int j = 0; // Pointer for pattern p
        int m = s.length();
        int n = p.length();
        
     
        int star_idx = -1; 
        int last_match = -1; 

        while (i < m) {
          
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            }
            
            else if (j < n && p[j] == '*') {
                star_idx = j;   
                last_match = i;   
                j++;              
            }
         
            else if (star_idx != -1) {
                // Backtrack!
                j = star_idx + 1;  
                last_match++;     
                i = last_match; 
            }
            else {
                return false;
            }
        }
        while (j < n && p[j] == '*') {
            j++;
        }
        return j == n;
    }
};