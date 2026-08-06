
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n = capacity.size();
        for (int i = 0; i < n; ++i) {
            capacity[i] -= rocks[i];
        }
        sort(capacity.begin(), capacity.end());

        int full_bags = 0;
        for (int i = 0; i < n; ++i) {
            if (capacity[i] == 0) {
                full_bags++;
            } else if (additionalRocks >= capacity[i]) {
                additionalRocks -= capacity[i];
                full_bags++;
            } else {
                break;
            }
        }

        return full_bags;
    }
};