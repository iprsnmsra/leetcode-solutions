#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = points.size();
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            long long x = points[i][0];
            long long y = points[i][1];
            
            if (y == 0) arr[i] = x;                             
            else if (x == side) arr[i] = side + y;               
            else if (y == side) arr[i] = 2LL * side + (side - x); 
            else arr[i] = 3LL * side + (side - y);                 
        }

        sort(arr.begin(), arr.end());

        vector<long long> circular_arr(2 * n);
        for (int i = 0; i < n; i++) {
            circular_arr[i] = arr[i];
            circular_arr[i + n] = arr[i] + 4LL * side;
        }

        long long low = 1, high = side; 
        long long best_distance = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            
            if (isValid(mid, circular_arr, n, k, side)) {
                best_distance = mid; 
                low = mid + 1;
            } else {
                high = mid - 1;     
            }
        }

        return best_distance;
    }

private:
    bool isValid(long long D, const vector<long long>& arr, int n, int k, int side) {
        vector<int> next_idx(2 * n, 2 * n);
        int j = 0;
        for (int i = 0; i < 2 * n; i++) {
            while (j < 2 * n && arr[j] - arr[i] < D) {
                j++;
            }
            if (j < 2 * n) {
                next_idx[i] = j;
            }
        }

        int limit = 0;
        while (limit < n && arr[limit] <= arr[0] + D) {
            limit++;
        }

        for (int i = 0; i < limit; i++) {
            int curr = i;
            int count = 1;

            while (count < k && curr < 2 * n) {
                curr = next_idx[curr];
                if (curr >= 2 * n) break; 
                count++;
            }
            if (count == k && arr[curr] <= arr[i] + 4LL * side - D) {
                return true;
            }
        }
        
        return false;
    }
};