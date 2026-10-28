#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
private:
    // Prefix sum of days preceding each month in a non-leap year (1-indexed)
    static constexpr int DAYS_BEFORE[13] = {
        0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
    };

    // Fast inline conversion from "MM-DD" -> Day of Year [1, 365]
    inline int dateToDay(const string& date) {
        int month = (date[0] - '0') * 10 + (date[1] - '0');
        int day   = (date[3] - '0') * 10 + (date[4] - '0');
        return DAYS_BEFORE[month] + day;
    }

public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        // Optimization: Fast I/O for execution supremacy
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // 1. Map calendar strings to 1D continuous integers
        int alice_start = dateToDay(arriveAlice);
        int alice_end   = dateToDay(leaveAlice);
        int bob_start   = dateToDay(arriveBob);
        int bob_end     = dateToDay(leaveBob);

        // 2. Compute 1D interval intersection bounds
        int overlap_start = max(alice_start, bob_start);
        int overlap_end   = min(alice_end, bob_end);

        // 3. O(1) Mathematical Length Evaluation
        return max(0, overlap_end - overlap_start + 1);
    }
};