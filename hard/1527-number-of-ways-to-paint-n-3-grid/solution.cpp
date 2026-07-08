class Solution {
public:
    int numOfWays(int n) {
        long long mod = 1e9 + 7;
        
        long long color3 = 6; 
        long long color2 = 6; 

        for (int i = 2; i <= n; ++i) {
            long long next_color3 = (2 * color3 + 2 * color2) % mod;
            long long next_color2 = (2 * color3 + 3 * color2) % mod;

            color3 = next_color3;
            color2 = next_color2;
        }

        return (color3 + color2) % mod;
    }
};