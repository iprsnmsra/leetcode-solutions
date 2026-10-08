class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = seq.length();
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = (i & 1) ^ (seq[i] & 1);
        }

        return res;
    }
};