#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int mostFrequentPrime(vector<vector<int>>& mat) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = mat.size();
        int n = mat[0].size();
        unordered_map<int, int> prime_freq;
        int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int d = 0; d < 8; ++d) {
                    int r = i;
                    int c = j;
                    int val = mat[r][c];
                    while (true) {
                        r += dx[d];
                        c += dy[d];
                        if (r < 0 || r >= m || c < 0 || c >= n) break;
                        

                        val = val * 10 + mat[r][c];

                        if (val > 10 && isPrime(val)) {
                            prime_freq[val]++;
                        }
                    }
                }
            }
        }
        int max_freq = -1;
        int best_prime = -1;

        for (const auto& [prime, count] : prime_freq) {
            if (count > max_freq) {
                max_freq = count;
                best_prime = prime;
            } else if (count == max_freq) {
                best_prime = max(best_prime, prime);
            }
        }

        return best_prime;
    }

private:
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
};