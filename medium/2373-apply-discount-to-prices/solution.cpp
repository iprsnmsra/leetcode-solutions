#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        string result;

        result.reserve(sentence.size()); 

        double multiplier = (100.0 - discount) / 100.0;
        
        int n = sentence.length();
        int i = 0;
        char buf[50]; 

        while (i < n) {
            int j = i;
            while (j < n && sentence[j] != ' ') {
                j++;
            }
            
            int len = j - i;
            bool is_price = false;
            long long price_val = 0; 

            if (len > 1 && sentence[i] == '$') {
                is_price = true;
                for (int k = i + 1; k < j; ++k) {
                    if (sentence[k] < '0' || sentence[k] > '9') {
                        is_price = false;
                        break;
                    }
                    price_val = price_val * 10 + (sentence[k] - '0');
                }
            }
            
            if (is_price) {
                double discounted = price_val * multiplier;
                snprintf(buf, sizeof(buf), "$%.2f", discounted);
                result.append(buf);
            } else {
                result.append(sentence, i, len);
            }

            if (j < n) {
                result.push_back(' ');
            }

            i = j + 1;
        }
        
        return result;
    }
};