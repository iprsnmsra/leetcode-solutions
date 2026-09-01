#include <string>
#include <vector>
#include <iostream>
#include <numeric> // For iota

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int fact[10];
        fact[0] = 1;
        for(int i = 1; i <= n; i++) {
            fact[i] = fact[i-1] * i;
        }
        vector<int> numbers;
        for(int i = 1; i <= n; i++) {
            numbers.push_back(i);
        }
        k--;

        string result = "";

        for(int i = n; i >= 1; i--) {
            int blockSize = fact[i - 1];
            
            // Determine the index of the number to pick
            int index = k / blockSize;
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= blockSize;
        }

        return result;
    }
};