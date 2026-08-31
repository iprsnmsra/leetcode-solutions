#pragma GCC optimize("O3", "unroll-loops")
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
       
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int n = nums.size();
        int m = k - 1;         
        int W = dist + 1;   
        
        multiset<int> L; 
        multiset<int> R; 
        long long sumL = 0;
        
        
        auto add = [&](int x) {
            if (L.size() < m) {
                L.insert(x);
                sumL += x;
            } else if (x < *L.rbegin()) {
                int max_L = *L.rbegin();
                L.erase(prev(L.end())); 
                sumL -= max_L;
                
                L.insert(x);           
                sumL += x;
                
                R.insert(max_L);       
            } else {
                R.insert(x);
            }
        };
        
      
        auto remove = [&](int x) {
            auto it = R.find(x);
            if (it != R.end()) {
                R.erase(it); 
            } else {
                L.erase(L.find(x)); 
                sumL -= x;
                
               
                if (!R.empty()) {
                    int min_R = *R.begin();
                    R.erase(R.begin());
                    L.insert(min_R);
                    sumL += min_R;
                }
            }
        };
        
        
        for (int i = 1; i <= W && i < n; ++i) {
            add(nums[i]);
        }
        
        long long min_sum = sumL;
        
       
        for (int i = W + 1; i < n; ++i) {
            remove(nums[i - W]); 
            add(nums[i]); 
            min_sum = min(min_sum, sumL);
        }
        return nums[0] + min_sum;
    }
};