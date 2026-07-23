#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int i = 0;
        int j = 0;
        int max_dist = 0;

        int n1 = nums1.size();
        int n2 = nums2.size();

        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                if (j - i > max_dist) {
                    max_dist = j - i;
                }
                j++;
            } 
            else {

                i++;
            }
        }

        return max_dist;
    }
};