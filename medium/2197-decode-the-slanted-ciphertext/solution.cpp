#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = encodedText.length();
        if (n == 0) return "";
        
        int cols = n / rows;
        string decoded = "";
        for (int start_col = 0; start_col < cols; ++start_col) {
            
            for (int r = 0; r < rows; ++r) {
                int c = start_col + r;
                if (c >= cols) {
                    break;
                }
                int idx = (r * cols) + c;
                decoded += encodedText[idx];
            }
        }
        int last_char_idx = decoded.find_last_not_of(' ');
        
        if (last_char_idx == string::npos) return ""; 
        
        return decoded.substr(0, last_char_idx + 1);
    }
};