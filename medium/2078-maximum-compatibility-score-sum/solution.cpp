#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int m = students.size();
        int n = students[0].size();

        vector<vector<int>> score_matrix(m, vector<int>(m, 0));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                int match_count = 0;
                for (int k = 0; k < n; ++k) {
                    if (students[i][k] == mentors[j][k]) {
                        match_count++;
                    }
                }
                score_matrix[i][j] = match_count;
            }
        }

        vector<vector<int>> memo(m, vector<int>(1 << m, -1));

        return solve(0, 0, m, score_matrix, memo);
    }

private:
    int solve(int student_idx, int mask, int m, 
              const vector<vector<int>>& score_matrix, vector<vector<int>>& memo) {

        if (student_idx == m) {
            return 0;
        }

        if (memo[student_idx][mask] != -1) {
            return memo[student_idx][mask];
        }

        int max_score = 0;
        for (int mentor_idx = 0; mentor_idx < m; ++mentor_idx) {

            if (!((mask >> mentor_idx) & 1)) {

                int current_score = score_matrix[student_idx][mentor_idx] + 
                                    solve(student_idx + 1, mask | (1 << mentor_idx), m, score_matrix, memo);
                
                max_score = max(max_score, current_score);
            }
        }

        return memo[student_idx][mask] = max_score;
    }
};