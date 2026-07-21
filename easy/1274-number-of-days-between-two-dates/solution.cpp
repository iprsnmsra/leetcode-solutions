#include <string>
#include <cmath>
#include <iostream>

using namespace std;

class Solution {
private:
    const int days_in_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysSince1971(int year, int month, int day) {
        int total_days = 0;

        for (int y = 1971; y < year; ++y) {
            total_days += isLeapYear(y) ? 366 : 365;
        }

        for (int m = 1; m < month; ++m) {
            total_days += days_in_month[m];

            if (m == 2 && isLeapYear(year)) {
                total_days += 1;
            }
        }

        total_days += day;

        return total_days;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int y1 = stoi(date1.substr(0, 4)), m1 = stoi(date1.substr(5, 2)), d1 = stoi(date1.substr(8, 2));
        int y2 = stoi(date2.substr(0, 4)), m2 = stoi(date2.substr(5, 2)), d2 = stoi(date2.substr(8, 2));
        int abs_days1 = daysSince1971(y1, m1, d1);
        int abs_days2 = daysSince1971(y2, m2, d2);

        return abs(abs_days1 - abs_days2);
    }
};