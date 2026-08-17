class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int freq[20005] = {0};
        for (const int& num : nums) {
            freq[num + 10000]++;
        }
        vector<int> unique_nums;
        unique_nums.reserve(20005); 
        for (int i = 0; i <= 20000; ++i) {
            if (freq[i] > 0) {
                unique_nums.push_back(i - 10000);
            }
        }
        nth_element(unique_nums.begin(), unique_nums.begin() + k - 1, unique_nums.end(), 
            [&freq](int a, int b) {
                return freq[a + 10000] > freq[b + 10000];
            }
        );
        return vector<int>(unique_nums.begin(), unique_nums.begin() + k);
    }
};