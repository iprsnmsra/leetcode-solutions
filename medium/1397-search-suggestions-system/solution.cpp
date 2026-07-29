#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        sort(products.begin(), products.end());

        vector<vector<string>> result;
        int left = 0;
        int right = products.size() - 1;
        for (int i = 0; i < searchWord.length(); ++i) {
            char c = searchWord[i];
            while (left <= right && (products[left].length() <= i || products[left][i] != c)) {
                left++;
            }
            while (left <= right && (products[right].length() <= i || products[right][i] != c)) {
                right--;
            }
            vector<string> currentSuggestions;
            int remain = right - left + 1;
            for (int j = 0; j < min(3, remain); ++j) {
                currentSuggestions.push_back(products[left + j]);
            }
            
            result.push_back(currentSuggestions);
        }

        return result;
    }
};