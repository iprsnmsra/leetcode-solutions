#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <cstdlib>

using namespace std;

class Solution {
private:
    int valid_len;
    unordered_map<int, int> reroute_map;

public:
    Solution(int n, vector<int>& blacklist) {
        valid_len = n - blacklist.size();
        
        unordered_set<int> bl_set(blacklist.begin(), blacklist.end());

        int tail = n - 1;
 
        for (int b : blacklist) {

            if (b < valid_len) {
                while (bl_set.count(tail)) {
                    tail--;
                }

                reroute_map[b] = tail;
                tail--; 
            }
        }
    }
    
    int pick() {
 
        int r = rand() % valid_len;

        if (reroute_map.count(r)) {
            return reroute_map[r];
        }

        return r;
    }
};