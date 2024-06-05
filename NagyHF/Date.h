#include <iostream>

#ifndef DATE_H
#define DATE_H

#include <string>

class Date {
private:
    int year;
    int month;
    int day;

public:
    Date() : year(0), month(0), day(0) {}

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    std::string getDate();
};

#endif // DATE_H