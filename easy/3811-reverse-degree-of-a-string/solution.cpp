class Solution {
public:
    int reverseDegree(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int total_degree = 0;
        for (int i = 0; i < s.length(); ++i) {
            int reverse_val = 'z' - s[i] + 1;
            total_degree += reverse_val * (i + 1);
        }
        
        return total_degree;
    }
};