class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = stoneValue.size();
        
        int dp_i1 = 0; 
        int dp_i2 = 0; 
        int dp_i3 = 0; 

        for (int i = n - 1; i >= 0; --i) {
            int max_diff = -1e9; 
            int take = 0;
            if (i < n) {
                take += stoneValue[i];
                max_diff = max(max_diff, take - dp_i1);
            }
            if (i + 1 < n) {
                take += stoneValue[i + 1];
                max_diff = max(max_diff, take - dp_i2);
            }
            if (i + 2 < n) {
                take += stoneValue[i + 2];
                max_diff = max(max_diff, take - dp_i3);
            }
            dp_i3 = dp_i2;
            dp_i2 = dp_i1;
            dp_i1 = max_diff;
        }
        if (dp_i1 > 0) return "Alice";
        if (dp_i1 < 0) return "Bob";
        return "Tie";
    }
};