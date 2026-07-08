#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        sort(arr.begin(), arr.end());
        
        vector<vector<int>> result;
        int min_diff = INT_MAX;

        for (int i = 1; i < arr.size(); ++i) {
            int current_diff = arr[i] - arr[i - 1];
            
            if (current_diff < min_diff) {
                min_diff = current_diff;
                result.clear();
                result.push_back({arr[i - 1], arr[i]});
                
            } else if (current_diff == min_diff) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        
        return result;
    }
};