class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (arr.empty()) return {};
        vector<int> sorted_arr = arr;
        sort(sorted_arr.begin(), sorted_arr.end());
        sorted_arr.erase(unique(sorted_arr.begin(), sorted_arr.end()), sorted_arr.end());
        unordered_map<int, int> rank_map;
        rank_map.reserve(sorted_arr.size()); 

        for (int i = 0; i < sorted_arr.size(); ++i) {
            rank_map[sorted_arr[i]] = i + 1;
        }
        for (int i = 0; i < arr.size(); ++i) {
            arr[i] = rank_map[arr[i]];
        }

        return arr;
    }
};