#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> result(n, 0);
        stack<int> st;
        int prev_time = 0;

        for (const string& log : logs) {
            
            int pos1 = log.find(':');
            int pos2 = log.find(':', pos1 + 1);
            
            int id = stoi(log.substr(0, pos1));
            string type = log.substr(pos1 + 1, pos2 - pos1 - 1);
            int time = stoi(log.substr(pos2 + 1));
            if (type == "start") {
                if (!st.empty()) {
                    result[st.top()] += (time - prev_time);
                }
                st.push(id);
                prev_time = time;
            } else {
                result[st.top()] += (time - prev_time + 1);
                st.pop();
                prev_time = time + 1;
            }
        }

        return result;
    }
};