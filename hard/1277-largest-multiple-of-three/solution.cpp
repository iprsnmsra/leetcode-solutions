class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int count[10] = {0};
        int sum = 0;
        for (int d : digits) {
            count[d]++;
            sum += d;
        }

        int rem = sum % 3;
        if (rem == 1) {
            if (count[1]) count[1]--;
            else if (count[4]) count[4]--;
            else if (count[7]) count[7]--;
            else {
                int needed = 2;
                for (int d : {2, 5, 8}) {
                    while (needed > 0 && count[d] > 0) {
                        count[d]--;
                        needed--;
                    }
                }
            }
        } else if (rem == 2) {
            if (count[2]) count[2]--;
            else if (count[5]) count[5]--;
            else if (count[8]) count[8]--;
            else {
                int needed = 2;
                for (int d : {1, 4, 7}) {
                    while (needed > 0 && count[d] > 0) {
                        count[d]--;
                        needed--;
                    }
                }
            }
        }
        string ans = "";
        for (int i = 9; i >= 0; --i) {
            if (count[i] > 0) {
                ans.append(count[i], '0' + i);
            }
        }
        if (ans.length() > 0 && ans[0] == '0') {
            return "0";
        }

        return ans;
    }
};