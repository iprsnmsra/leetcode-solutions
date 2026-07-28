class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count[1001] = {0};
        for (int num : arr1) {
            count[num]++;
        }

        vector<int> result;
        result.reserve(arr1.size());
        for (int num : arr2) {
            while (count[num] > 0) {
                result.push_back(num);
                count[num]--;
            }
        }
        for (int i = 0; i <= 1000; ++i) {
            while (count[i] > 0) {
                result.push_back(i);
                count[i]--;
            }
        }

        return result;
    }
};