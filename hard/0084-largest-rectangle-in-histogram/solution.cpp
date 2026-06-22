#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        stack<int> st;
        int max_area = 0;
        int n = heights.size();

        for (int i = 0; i <= n; ++i) {

            int curr_height = (i == n) ? 0 : heights[i];

            while (!st.empty() && curr_height < heights[st.top()]) {
                
                int h = heights[st.top()];
                st.pop();

                int width;
                if (st.empty()) {
                    width = i; 
                } else {
                    width = i - st.top() - 1;
                }

                max_area = max(max_area, h * width);
            }
            st.push(i);
        }

        return max_area;
    }
};