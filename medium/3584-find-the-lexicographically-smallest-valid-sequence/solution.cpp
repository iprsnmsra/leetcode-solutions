class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = word1.length();
        int m = word2.length();
        vector<int> right_match(m, -1);
        int j = m - 1;
        for (int i = n - 1; i >= 0 && j >= 0; --i) {
            if (word1[i] == word2[j]) {
                right_match[j] = i;
                j--;
            }
        }

        vector<int> seq;
        seq.reserve(m); 
        
        bool changed = false;
        j = 0;
        for (int i = 0; i < n && j < m; ++i) {
            if (word1[i] == word2[j]) {
                seq.push_back(i);
                j++;
            } else if (!changed) {
                bool future_viable = (j + 1 == m) || (right_match[j + 1] >= i + 1);
                
                if (future_viable) {
                    changed = true;
                    seq.push_back(i);
                    j++;
                }
            }
        }
        if (j == m) {
            return seq;
        }
        return {};
    }
};