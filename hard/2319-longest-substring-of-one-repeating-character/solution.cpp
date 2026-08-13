struct Node {
    int max_len;
    int pref_len;
    int suff_len;
    char pref_char;
    char suff_char;
    int size;
};

class Solution {
    vector<Node> tree;
    string s;
    void merge_nodes(int v) {
        Node& res = tree[v];
        const Node& left = tree[2 * v];
        const Node& right = tree[2 * v + 1];

        res.size = left.size + right.size;
        res.pref_char = left.pref_char;
        res.suff_char = right.suff_char;
        res.pref_len = left.pref_len;
        if (left.pref_len == left.size && left.pref_char == right.pref_char) {
            res.pref_len += right.pref_len;
        }
        res.suff_len = right.suff_len;
        if (right.suff_len == right.size && right.suff_char == left.suff_char) {
            res.suff_len += left.suff_len;
        }
        res.max_len = max(left.max_len, right.max_len);
        if (left.suff_char == right.pref_char) {
            res.max_len = max(res.max_len, left.suff_len + right.pref_len);
        }
    }

    void build(int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {1, 1, 1, s[tl], s[tl], 1};
            return;
        }
        int tm = tl + (tr - tl) / 2;
        build(2 * v, tl, tm);
        build(2 * v + 1, tm + 1, tr);
        merge_nodes(v);
    }

    void update(int v, int tl, int tr, int pos, char c) {
        if (tl == tr) {
            tree[v] = {1, 1, 1, c, c, 1};
            return;
        }
        int tm = tl + (tr - tl) / 2;
        if (pos <= tm) {
            update(2 * v, tl, tm, pos, c);
        } else {
            update(2 * v + 1, tm + 1, tr, pos, c);
        }
        merge_nodes(v);
    }

public:
    vector<int> longestRepeating(string s_in, string queryCharacters, vector<int>& queryIndices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        s = s_in;
        int n = s.length();
        tree.resize(4 * n);
        
        build(1, 0, n - 1);

        int k = queryCharacters.length();
        vector<int> ans;
        ans.reserve(k);

        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]); 
            ans.push_back(tree[1].max_len);
        }

        return ans;
    }
};