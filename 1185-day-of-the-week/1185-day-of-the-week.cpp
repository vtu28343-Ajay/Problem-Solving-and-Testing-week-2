class Solution {
private:
    bool isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

public:
    string dayOfTheWeek(int day, int month, int year) {
        vector<string> days = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        // Total days since December 31, 1970
        // January 1, 1971 was a Friday, so offset by 5 (0 = Sunday, ..., 5 = Friday)
        int totalDays = 0;

        // Add days for all complete years since 1971
        for (int y = 1971; y < year; ++y) {
            totalDays += isLeapYear(y) ? 366 : 365;
        }

        // Add days for complete months in the target year
        for (int m = 0; m < month - 1; ++m) {
            totalDays += daysInMonth[m];
            if (m == 1 && isLeapYear(year)) {
                totalDays += 1; // February in a leap year
            }
        }

        // Add the days in the current month
        totalDays += day;

        // January 1, 1971 was a Friday (index 5)
        return days[(totalDays + 4) % 7];
    }
};