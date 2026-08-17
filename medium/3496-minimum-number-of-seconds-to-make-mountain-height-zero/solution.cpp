#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        long long low = 1;
    
        long long high = 1e16; 
        long long ans = high;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long total_reduced = 0;

            for (int time : workerTimes) {
        
                long long K = mid / time; 
                long long x = sqrt(2.0 * K);
                while (x * (x + 1) / 2 > K) x--;
                while ((x + 1) * (x + 2) / 2 <= K) x++;
                total_reduced += x;
                if (total_reduced >= mountainHeight) {
                    break;
                }
            }
            if (total_reduced >= mountainHeight) {
                ans = mid;       
                high = mid - 1;  
            } else {
                low = mid + 1;   
            }
        }

        return ans;
    }
};