#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> count_stack;
        vector<string> string_stack;
        
        string current_string = "";
        int current_number = 0;

        for (char c : s) {
            if (isdigit(c)) {
                current_number = (current_number * 10) + (c - '0');
            } 
            else if (c == '[') {
                count_stack.push_back(current_number);
                string_stack.push_back(current_string);
                current_number = 0;
                current_string = "";
            } 
            else if (c == ']') {
                int multiplier = count_stack.back();
                count_stack.pop_back();
                
                string previous_string = string_stack.back();
                string_stack.pop_back();
                string temp = "";
                for (int i = 0; i < multiplier; ++i) {
                    temp += current_string;
                }
                
                current_string = previous_string + temp;
            } 
            else {
                current_string += c;
            }
        }

        return current_string;
    }
};