class Solution {
private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    int daysFrom1900(string date) {
        int y = stoi(date.substr(0, 4));
        int m = stoi(date.substr(5, 2));
        int d = stoi(date.substr(8, 2));

        int days = 0;

        // Add days for complete years from 1900 to y - 1
        for (int i = 1900; i < y; ++i) {
            days += isLeapYear(i) ? 366 : 365;
        }

        // Days in each month for a non-leap year
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Add days for complete months in the current year
        for (int i = 0; i < m - 1; ++i) {
            days += daysInMonth[i];
            if (i == 1 && isLeapYear(y)) {
                days += 1; // February in a leap year
            }
        }

        // Add remaining days
        days += d;

        return days;
    }

public:
    int daysBetweenDates(string date1, string date2) {
        return abs(daysFrom1900(date1) - daysFrom1900(date2));
    }
};