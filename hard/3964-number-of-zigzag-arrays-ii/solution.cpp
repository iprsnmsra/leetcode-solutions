#include <vector>
#include <iostream>

using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    using Matrix = vector<vector<long long>>;
    Matrix multiply(const Matrix& A, const Matrix& B, int S) {
        Matrix C(S, vector<long long>(S, 0));
        for (int i = 0; i < S; ++i) {
            for (int k = 0; k < S; ++k) {
                if (A[i][k] == 0) continue;
                
                for (int j = 0; j < S; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }
    Matrix power(Matrix A, long long exp, int S) {
        Matrix res(S, vector<long long>(S, 0));
        
        for (int i = 0; i < S; ++i) res[i][i] = 1; 

        while (exp > 0) {
            if (exp % 2 == 1) res = multiply(res, A, S);
            A = multiply(A, A, S);
            exp /= 2;
        }
        return res;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int K = r - l + 1;
        int S = 2 * K; 

        Matrix M(S, vector<long long>(S, 0));

        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                int val_i = (i < K) ? (i + 1) : (i - K + 1);
                int val_j = (j < K) ? (j + 1) : (j - K + 1);

                if (j < K && i >= K) {
                    if (val_i > val_j) M[i][j] = 1;
                } else if (j >= K && i < K) {
                    if (val_i < val_j) M[i][j] = 1;
                }
            }
        }

        Matrix M_final = power(M, n - 1, S);

        long long total_valid = 0;
        for (int i = 0; i < S; ++i) {
            for (int j = 0; j < S; ++j) {
                total_valid = (total_valid + M_final[i][j]) % MOD;
            }
        }

        return total_valid;
    }
};