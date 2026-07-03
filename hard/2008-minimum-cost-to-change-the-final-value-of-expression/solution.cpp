class Solution {
    void collapse(stack<pair<int, int>>& vals, stack<char>& ops) {
        if (vals.size() < 2 || ops.empty() || ops.top() == '(') return;

        auto R = vals.top(); vals.pop();
        auto L = vals.top(); vals.pop();
        char op = ops.top(); ops.pop();

        int L0 = L.first, L1 = L.second;
        int R0 = R.first, R1 = R.second;

        int c0 = 1e9, c1 = 1e9;

        if (op == '&') {
            c0 = min({L0 + R0, L0 + R1, L1 + R0, L0 + R0 + 1});
            c1 = min({L1 + R1, L1 + R1 + 1, L0 + R1 + 1, L1 + R0 + 1});
        } else if (op == '|') {
            c0 = min({L0 + R0, L0 + R0 + 1, L0 + R1 + 1, L1 + R0 + 1});
            c1 = min({L1 + R1, L0 + R1, L1 + R0, L1 + R1 + 1});
        }
        vals.push({c0, c1});
    }

public:
    int minOperationsToFlip(string expression) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        stack<pair<int, int>> vals;
        stack<char> ops;

        for (char c : expression) {
            if (c == '0') {
                vals.push({0, 1});
                collapse(vals, ops);
            } else if (c == '1') {
                vals.push({1, 0});
                collapse(vals, ops);
            } else if (c == '(' || c == '&' || c == '|') {
                ops.push(c);
            } else if (c == ')') {
                ops.pop(); 
                collapse(vals, ops);
            }
        }

        return max(vals.top().first, vals.top().second);
    }
};