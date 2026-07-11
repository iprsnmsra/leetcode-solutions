#include <string>
#include <set>

using namespace std;

class Solution {
private:
    bool isPrime(long long n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;

        for (long long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        
        return true;
    }

public:
    long long sumOfLargestPrimes(string s) {
        set<long long, greater<long long>> unique_nums;
        int n = s.length();

        for (int i = 0; i < n; ++i) {
            for (int len = 1; i + len <= n; ++len) {
                string sub = s.substr(i, len);

                unique_nums.insert(stoll(sub)); 
            }
        }

        long long sum = 0;
        int count = 0;

        for (long long num : unique_nums) {
            if (isPrime(num)) {
                sum += num;
                count++;
                if (count == 3) break;
            }
        }

        return sum;
    }
};