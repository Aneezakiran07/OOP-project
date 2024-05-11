#include "Date.h"
#include<iostream>

using namespace std;

Date::Date(int x, int y, int z) : day(x), month(y), year(z) {}

void Date::readData(ifstream& inp)
{
    inp >> day;
    inp >> month;
    inp >> year;
}

bool Date::compareyear_mem(const Date& rhs, bool isMemory) {
    if (!isMemory && year != rhs.year) {
        return false;
    }
    else if (month == rhs.month) {
        if (day == rhs.day || day + 1 == rhs.day || day - 1 == rhs.day) {
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
    int ans = lhs.year - rhs.year;
    return (ans < 0) ? -ans : ans;
}

void Date::display() {
    std::cout << day << "/" << month << "/" << year;
}

void Date::SetterofData(int d, int m, int y) {
    day = d;
    month = m;
    year = y;
}

Date Date::CurrentDate;