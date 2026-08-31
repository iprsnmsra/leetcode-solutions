#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    long long MOD = 1e9 + 7;

    vector<vector<long long>> multiply(vector<vector<long long>>& A, vector<vector<long long>>& B) {
        vector<vector<long long>> C(2, vector<long long>(2));
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                for (int l = 0; l < 2; l++) {
                    C[i][j] = (C[i][j] + A[i][l] * B[l][j]) % MOD;
                }
            }
        }
        return C;
    }

    // Matrix Exponentiation
    vector<vector<long long>> power(vector<vector<long long>> A, long long k) {
        vector<vector<long long>> res(2, vector<long long>(2));
        res[0][0] = 1; res[1][1] = 1; // Identity
        while (k > 0) {
            if (k & 1) res = multiply(res, A);
            A = multiply(A, A);
            k >>= 1;
        }
        return res;
    }
    int countOccurrences(string s, string t) {
        int n = t.length();
        string text = s + s;
        text.pop_back();
        vector<int> lps(n, 0);
        int len = 0, i = 1;
        while (i < n) {
            if (t[i] == t[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) len = lps[len - 1];
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        int count = 0;
        i = 0; // index for text
        int j = 0; // index for t
        while (i < text.length()) {
            if (t[j] == text[i]) {
                j++;
                i++;
            }
            if (j == n) {
                count++;
                j = lps[j - 1];
            } else if (i < text.length() && t[j] != text[i]) {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return count;
    }

public:
    int numberOfWays(string s, string t, long long k) {
        int n = s.length();
        int c = countOccurrences(s, t);
        vector<vector<long long>> M = {
            { (long long)(MOD - 1), (long long)c },
            { 0, (long long)(n - 1) }
        };

        M = power(M, k);
        long long a_0 = (s == t) ? 1 : 0;
        
        long long result = (M[0][0] * a_0 + M[0][1] * 1) % MOD;
        return result;
    }
};