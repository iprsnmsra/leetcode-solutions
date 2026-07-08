class Solution {
private:

    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;

        if (n % 2 == 0 || n % 3 == 0) return false;
        for (int i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
        }
        
        return true;
    }

public:
    bool completePrime(int num) {

        int temp = num;
        while (temp > 0) {
            if (!isPrime(temp)) return false;
            temp /= 10;
        }
        long long div = 10;
        while (div <= num) {
            if (!isPrime(num % div)) return false;
            div *= 10;
        }
        
        return true;
    }
};