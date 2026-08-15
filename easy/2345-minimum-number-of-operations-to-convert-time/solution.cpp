#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int current_mins = ((current[0] - '0') * 10 + (current[1] - '0')) * 60 
                         + ((current[3] - '0') * 10 + (current[4] - '0'));
                         
        int correct_mins = ((correct[0] - '0') * 10 + (correct[1] - '0')) * 60 
                         + ((correct[3] - '0') * 10 + (correct[4] - '0'));
                         
        int diff = correct_mins - current_mins;
        int operations = 0;
        
        operations += diff / 60;
        diff %= 60;

        operations += diff / 15;
        diff %= 15;
        operations += diff / 5;
        diff %= 5;
        operations += diff; 
        
        return operations;
    }
};