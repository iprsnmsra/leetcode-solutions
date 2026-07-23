#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

class Solution {
public:
    int numDifferentIntegers(string word) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        unordered_set<string> unique_nums;
        string current_num = "";

        for (int i = 0; i <= word.length(); ++i) {
            
            if (i < word.length() && isdigit(word[i])) {

                current_num += word[i];
            } 
            else if (!current_num.empty()) {
                
                int start = 0;
                while (start < current_num.length() && current_num[start] == '0') {
                    start++;
                }

                if (start == current_num.length()) {
                    unique_nums.insert("0");
                } 

                else {
                    unique_nums.insert(current_num.substr(start));
                }

                current_num = "";
            }
        }
        
        return unique_nums.size();
    }
};