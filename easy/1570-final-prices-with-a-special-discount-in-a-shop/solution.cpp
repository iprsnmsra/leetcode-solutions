#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = prices.size();

        vector<int> answer = prices; 

        stack<int> st;

        for (int i = 0; i < n; ++i) {
            
            while (!st.empty() && prices[i] <= prices[st.top()]) {

                int waiting_index = st.top();
                st.pop();

                answer[waiting_index] -= prices[i];
            }
            st.push(i);
        }

        return answer;
    }
};