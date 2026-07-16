#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        long long n = grades.size();
        return (int)((sqrt(1 + 8 * n) - 1) / 2);
    }
};