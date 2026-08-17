#include <vector>
#include <iostream>

using namespace std;

class Fancy {
private:
    vector<long long> seq;
    long long A;
    long long B;
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }
    long long modInverse(long long n) {
        return power(n, MOD - 2);
    }

public:
    Fancy() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        A = 1;
        B = 0;
        seq.reserve(100000); 
    }
    
    void append(int val) {
        long long normalized_val = (val - B + MOD) % MOD;
        long long X = (normalized_val * modInverse(A)) % MOD;
        
        seq.push_back(X);
    }
    
    void addAll(int inc) {
    
        B = (B + inc) % MOD;
    }
    
    void multAll(int m) {
        A = (A * m) % MOD;
        B = (B * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= seq.size()) {
            return -1;
        }
        long long true_val = (seq[idx] * A + B) % MOD;
        return (int)true_val;
    }
};
/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */