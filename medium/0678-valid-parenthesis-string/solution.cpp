class Solution {
public:
    bool checkValidString(string s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int cmin = 0; 
        int cmax = 0; 

        for (char c : s) {
        
            if (c == '(') {
                cmax++;
                cmin++;
            } else if (c == ')') {
                cmax--;
                cmin--;
            } else if (c == '*') {
                cmax++; 
                cmin--; 
            }
            if (cmax < 0) {
                return false;
            }
            cmin = max(cmin, 0);
        }
        return cmin == 0;
    }
};