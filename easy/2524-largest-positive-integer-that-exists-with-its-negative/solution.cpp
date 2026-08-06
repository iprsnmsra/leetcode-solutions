class Solution {
public:
    int findMaxK(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int max_k = -1;
        char seen[2001] = {0}; 

        for (const int& num : nums) {
            if (seen[-num + 1000]) {
                int magnitude = abs(num);
                if (magnitude > max_k) {
                    max_k = magnitude;
                }
            }
            seen[num + 1000] = 1; 
        }

        return max_k;
    }
};