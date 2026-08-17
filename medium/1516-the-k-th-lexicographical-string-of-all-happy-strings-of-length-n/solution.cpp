#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int total_strings = 3 * (1 << (n - 1));
    
        if (k > total_strings) return "";

        string result = "";
        result.reserve(n); 
        
        k--; 

        int block_size = 1 << (n - 1);
        int first_char_idx = k / block_size;
        result += (char)('a' + first_char_idx);
        k %= block_size; 
        for (int i = n - 2; i >= 0; --i) {
            block_size = 1 << i;           
            int next_choice = k / block_size;
            char prev = result.back();
            if (prev == 'a') {
                result += (next_choice == 0) ? 'b' : 'c';
            } else if (prev == 'b') {
                result += (next_choice == 0) ? 'a' : 'c';
            } else { 
                result += (next_choice == 0) ? 'a' : 'b';
            }
            k %= block_size;
        }

        return result;
    }
};