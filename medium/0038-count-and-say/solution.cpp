#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (n == 1) return "1";

        string current = "1";
        for (int i = 2; i <= n; ++i) {
            string next_str = "";
            next_str.reserve(current.length() * 2); 
            
            int len = current.length();
            int j = 0;

            while (j < len) {
                int count = 1;
                while (j + count < len && current[j] == current[j + count]) {
                    count++;
                }
                

                next_str += (char)(count + '0');
                next_str += current[j];
                
                j += count;
            }
            
            current = next_str;
        }

        return current;
    }
};