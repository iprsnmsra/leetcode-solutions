#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<int> result;
        backtrack(num, 0, result);
        return result;
    }
    
private:
    bool backtrack(const string& num, int index, vector<int>& result) {
        if (index == num.length() && result.size() >= 3) {
            return true;
        }
        
        long long current_num = 0;
        
        for (int i = index; i < num.length(); ++i) {
            if (num[index] == '0' && i > index) {
                break;
            }
            current_num = current_num * 10 + (num[i] - '0');

            if (current_num > 2147483647) {
                break;
            }
            if (result.size() >= 2) {
                long long sum = (long long)result[result.size() - 1] + result[result.size() - 2];
                
                if (current_num > sum) {
                    break;
                } else if (current_num < sum) {
                    continue; 
                }
            }
            result.push_back(current_num);
            if (backtrack(num, i + 1, result)) {
                return true;
            }
            result.pop_back();
        }
        
        return false;
    }
};