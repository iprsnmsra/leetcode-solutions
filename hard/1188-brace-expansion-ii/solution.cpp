class Solution {
private:
    vector<string> combine(const vector<string>& a, const vector<string>& b) {
        vector<string> c;
        c.reserve(a.size() * b.size()); 
        for (const string& x : a) {
            for (const string& y : b) {
                c.push_back(x + y);
            }
        }
        return c;
    }
    void unite(vector<string>& a, const vector<string>& b) {
        a.insert(a.end(), b.begin(), b.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
    }

public:
    vector<string> braceExpansionII(string expression) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<string> res;
        vector<string> cur = {""};
        stack<pair<vector<string>, vector<string>>> st;
        for (char c : expression) {
            if (c == '{') {
                st.push({res, cur});
                res.clear();
                cur = {""};
            } 
            else if (c == '}') {
                unite(res, cur);
                auto [prev_res, prev_cur] = st.top(); 
                st.pop();
                
                cur = combine(prev_cur, res);
                res = prev_res;
            } 
            else if (c == ',') {
                unite(res, cur);
                cur = {""};
            } 
            else {
                cur = combine(cur, {string(1, c)});
            }
        }
        unite(res, cur);
        return res;
    }
};