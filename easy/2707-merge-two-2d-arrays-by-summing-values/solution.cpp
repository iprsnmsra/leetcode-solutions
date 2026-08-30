#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        
        vector<vector<int>> result;
        result.reserve(n + m);
        while (i < n && j < m) {
            if (nums1[i][0] == nums2[j][0]) {
             
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
              
                result.push_back(nums1[i]);
                i++;
            } else {
    
                result.push_back(nums2[j]);
                j++;
            }
        }
        while (i < n) {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < m) {
            result.push_back(nums2[j]);
            j++;
        }

        return result;
    }
};