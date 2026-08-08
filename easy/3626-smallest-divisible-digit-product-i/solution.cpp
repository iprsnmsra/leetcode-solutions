class Solution {
public:
    int smallestNumber(int n, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        while (true) {
            int product = 1;
            int temp = n;
            while (temp > 0) {
                product *= (temp % 10);
                if (product == 0) break;
                
                temp /= 10;
            }
            if (product % t == 0) {
                return n;
            }
            
            n++; 
        }
    }
};