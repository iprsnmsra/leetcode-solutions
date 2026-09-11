class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {0};
        for (int d : digits) {
            freq[d]++;
        }

        int valid_count = 0;
        for (int i = 100; i <= 998; i += 2) {
            int ones = i % 10;
            int tens = (i / 10) % 10;
            int hundreds = i / 100;
            freq[ones]--;
            freq[tens]--;
            freq[hundreds]--;
            if (freq[ones] >= 0 && freq[tens] >= 0 && freq[hundreds] >= 0) {
                valid_count++;
            }
            freq[ones]++;
            freq[tens]++;
            freq[hundreds]++;
        }

        return valid_count;
    }
};