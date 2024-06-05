#include "Date.h"
#include <string>

void Date::setYear(int y) {
    year = y;
}

void Date::setMonth(int m) {
    month = m;
}

void Date::setDay(int d) {
    day = d;
}

std::string Date::getDate() {
    std::string Str_day = std::to_string(day);
    std::string Str_month = std::to_string(month);
    std::string date;

    if (Str_day.length() == 1) {
        date = "0" + Str_day;
    }
    else {
        date = Str_day;
    }

    date = date + ':';

    if (Str_month.length() == 1) {
        date = date + "0" + Str_month;
    }
    else {
        date = date + Str_month;
    }

    date = date + ':';
    date = date + std::to_string(year);

    return date;
}