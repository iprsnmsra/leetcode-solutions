#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        // Optimization 1: Odd length strings cannot be valid
        if (s.length() % 2 != 0) return false;

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Using a string as a stack reduces memory overhead compared to std::stack<char>
        string st;
        st.reserve(s.length()); // Pre-allocate memory to avoid re-allocations

        for (char c : s) {
            // The "Push Expected" Strategy
            if (c == '(') {
                st.push_back(')');
            } else if (c == '{') {
                st.push_back('}');
            } else if (c == '[') {
                st.push_back(']');
            } else {
                // If it's a closing bracket:
                // 1. Stack cannot be empty (no opening bracket for this closer)
                // 2. The top of stack must match this closer
                if (st.empty() || st.back() != c) {
                    return false;
                }
                st.pop_back();
            }
        }

        // If stack is empty, all brackets were matched correctly
        return st.empty();
    }
};