#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
   
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> result;
        int n = s.length();

        if (n > 12 || n < 4) return result;

     
        for (int len1 = 1; len1 <= 3; ++len1) {
            for (int len2 = 1; len2 <= 3; ++len2) {
                for (int len3 = 1; len3 <= 3; ++len3) {
                    
              
                    int len4 = n - len1 - len2 - len3;
                    
                    
                    if (len4 > 0 && len4 <= 3) {
                        
                      
                        string s1 = s.substr(0, len1);
                        string s2 = s.substr(len1, len2);
                        string s3 = s.substr(len1 + len2, len3);
                        string s4 = s.substr(len1 + len2 + len3, len4);
                        
                    
                        if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4)) {
                            result.push_back(s1 + "." + s2 + "." + s3 + "." + s4);
                        }
                    }
                }
            }
        }
        
        return result;
    }

private:

    bool isValid(const string& segment) {

        if (segment.length() > 1 && segment[0] == '0') return false;
        int val = 0;
        for (char c : segment) {
            val = val * 10 + (c - '0');
        }
        
        return val <= 255;
    }
};