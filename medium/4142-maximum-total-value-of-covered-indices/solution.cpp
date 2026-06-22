#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        string velunqari = s;
        
        long long total_sum = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == '1') {
                int j = i;
                while (j + 1 < n && s[j + 1] == '1') {
                    j++;
                }
                
                if (i > 0) {
                    long long current_sum = 0;
                    int current_min = nums[i - 1]; 
                    
                    for (int k = i - 1; k <= j; k++) {
                        current_sum += nums[k];
                        if (nums[k] < current_min) {
                            current_min = nums[k];
                        }
                    }
                    total_sum += (current_sum -current_min);
                } else {
                    for (int k = 0; k <= j; k++) {
                        total_sum += nums[k];
                    }
                }
                i = j + 1;
            } else {
                i++;
            }
        }
        
        return total_sum;
    }
};