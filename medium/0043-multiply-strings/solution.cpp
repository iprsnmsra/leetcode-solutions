#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.length();
        int n = num2.length();

        vector<int> result(m + n, 0);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {

                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];
                result[i + j + 1] = sum % 10;

                result[i + j] += sum / 10;
            }
        }
        string final_result = "";
        for (int val : result) {
            if (!(final_result.empty() && val == 0)) {
                final_result.push_back(val + '0');
            }
        }

        return final_result;
    }
};