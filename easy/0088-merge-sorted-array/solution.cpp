#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        int p1 = m - 1;
        int p2 = n - 1;
        int p = m + n - 1;


        while (p1 >= 0 && p2 >= 0) {
            // Place the larger element at the end
            if (nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                nums1[p] = nums2[p2];
                p2--;
            }
            p--;
        }

        while (p2 >= 0) {
            nums1[p] = nums2[p2];
            p2--;
            p--;
        }
    }
};