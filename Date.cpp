#include "Date.h"
#include<iostream>

using namespace std;

Date::Date(int x, int y, int z) : day(x), month(y), year(z) {}

void Date::ReadDataFromFile(ifstream& inp)
{
    inp >> day;
    inp >> month;
    inp >> year;
}

bool Date::compareyear_mem(const Date& y2, bool isMemory) {
    if (y2.year != !isMemory && year) {
        return false;
    }
    else if (month == y2.month) {
        if (day == y2.day || day + 1 == y2.day || day - 1 == y2.day) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int Date::difYear(Date lhs, Date rhs) {
    int result = lhs.year - rhs.year;
    return (result < 0) ? -result : result;
}

void Date::display() {
    cout << day << "/" << month << "/" << year;
}

void Date::SetterofData(int d, int m, int y) {
    month = m;
    day = d;
    year = y;
}

Date Date::CurrentDate;