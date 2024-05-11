#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Date {
private:
    int day;
    int month;
    int year;

public:

    Date(int x = 0, int y = 0, int z = 0);
    void readData(ifstream& input);
    bool compareyear_mem(const Date& rhs, bool memory);
    void display();
    void SetterofData(int d, int m, int y);
    static int difYear(Date lhs, Date rhs);
    static Date CurrentDate;
};

#endif 
