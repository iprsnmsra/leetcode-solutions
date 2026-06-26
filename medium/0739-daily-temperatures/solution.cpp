#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = temperatures.size();
        vector<int> answer(n, 0); 
        stack<int> waiting_room;

        for (int i = 0; i < n; ++i) {
            int current_temp = temperatures[i];
            while (!waiting_room.empty() && current_temp > temperatures[waiting_room.top()]) {
                
                int prev_day = waiting_room.top();
                waiting_room.pop();
                answer[prev_day] = i - prev_day;
            }
            waiting_room.push(i);
        }

        return answer;
    }
};