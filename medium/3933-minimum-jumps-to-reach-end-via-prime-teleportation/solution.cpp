#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = nums.size();
        if (n <= 1) return 0;

        int max_val = 0;
        for (int x : nums) {
            if (x > max_val) max_val = x;
        }

        vector<int> spf(max_val + 1);
        for (int i = 0; i <= max_val; ++i) spf[i] = i;
        for (int i = 2; i * i <= max_val; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_val; j += i) {
                    if (spf[j] == j) spf[j] = i;
                }
            }
        }
        vector<vector<int>> multiples(max_val + 1);
        for (int i = 0; i < n; ++i) {
            int temp = nums[i];
            while (temp > 1) {
                int p = spf[temp];
                multiples[p].push_back(i);
                while (temp % p == 0) {
                    temp /= p;
                }
            }
        }

        vector<int> dist(n, -1);
        vector<bool> prime_used(max_val + 1, false);
        queue<int> q;
        
        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == n - 1) return dist[curr];

            if (curr + 1 < n && dist[curr + 1] == -1) {
                dist[curr + 1] = dist[curr] + 1;
                q.push(curr + 1);
            }
            if (curr - 1 >= 0 && dist[curr - 1] == -1) {
                dist[curr - 1] = dist[curr] + 1;
                q.push(curr - 1);
            }
            int val = nums[curr];

            if (val >= 2 && spf[val] == val) { 
                if (!prime_used[val]) {
                    prime_used[val] = true; 
                    
                    for (int j : multiples[val]) {
                        if (dist[j] == -1) {
                            dist[j] = dist[curr] + 1;
                            q.push(j);
                        }
                    }
                }
            }
        }

        return -1;
    }
};