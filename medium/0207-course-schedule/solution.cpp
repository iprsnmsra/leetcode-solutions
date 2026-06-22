#include <vector>
#include <queue>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for (const auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            
            adj[prereq].push_back(course);
            indegree[course]++; 
        }

        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int courses_taken = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            
            courses_taken++;

            for (int next_course : adj[curr]) {
                indegree[next_course]--;

                if (indegree[next_course] == 0) {
                    q.push(next_course);
                }
            }
        }

        return courses_taken == numCourses;
    }
};