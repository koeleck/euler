#include <iostream>


enum Month : int {
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    MAY,
    JUNE,
    JULY,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

enum DayOfWeek : int {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

int daysOfMonth(const Month month, const int year)
{
    switch (month) {
    case SEPTEMBER:
    case APRIL:
    case JUNE:
    case NOVEMBER:
        return 30;
    case FEBRUARY:
        {
            if (year % 4 != 0)
                return 28;
            else if (year % 100 != 0)
                return 29;
            else if (year % 400 != 0)
                return 28;
            else
                return 29;
        }
    case JANUARY:
    case MARCH:
    case MAY:
    case JULY:
    case AUGUST:
    case OCTOBER:
    case DECEMBER:
        return 31;
    }
}

int main()
{
    DayOfWeek day = MONDAY;
    Month month = JANUARY;
    int year = 1900;

    int result = 0;
    do {
        if (year > 1900 && day == SUNDAY)
            result++;
        day = static_cast<DayOfWeek>((day + daysOfMonth(month, year)) % 7);
        if (month == DECEMBER)
            ++year;
        month = static_cast<Month>((month + 1) % 12);
    } while (year < 2001);

    std::cout << "result: " << result << '\n';
}
