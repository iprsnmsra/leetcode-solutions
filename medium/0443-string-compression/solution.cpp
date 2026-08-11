#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = chars.size();
        int write = 0; 
        int read = 0;  

        while (read < n) {
            char current_char = chars[read];
            int count = 0;
            while (read < n && chars[read] == current_char) {
                read++;
                count++;
            }

            chars[write++] = current_char;

            if (count > 1) {
                string count_str = to_string(count);
                for (char digit : count_str) {
                    chars[write++] = digit;
                }
            }
        }
        return write;
    }
};