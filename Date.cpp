#include "Date.h"
#include "Helpers.h"
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

Date::Date() {
  day = 0;
  month = 0;
  year = 0;
}

Date::Date(string dateValue) {
    string* result = Helpers::validateDateString(dateValue);

    if (result == NULL) {
        cout << "Data incorrect" << endl;
        delete[] result;
        return;
    }

    setDay(stoi(result[0]));
    setMonth(stoi(result[1]));
    setYear(stoi(result[2]));

    delete[] result;
}

Date::Date(int dayValue, int monthValue, int yearValue) {
  day = dayValue;
  month = monthValue;
  year = yearValue;
}

void Date::setDate(string dateValue) {
    string* result = Helpers::validateDateString(dateValue);

    if (result == NULL) {
        cout << "Data incorrect" << endl;
        delete[] result;
        return;
    }

    setDay(stoi(result[0]));
    setMonth(stoi(result[1]));
    setYear(stoi(result[2]));

    delete[] result;
}

void Date::setDay(int dayValue) {
  day = dayValue;
}

void Date::setMonth(int monthValue) {
  month = monthValue;
}

void Date::setYear(int yearValue) {
  year = yearValue;
}

int Date::getDay() {
  return day;
}

int Date::getMonth() {
  return month;
}

int Date::getYear() {
  return year;
}

void Date::printDate() {
  if (day == 0 && month == 0) {
    cout << year << endl;
  } else {
    cout << day << "." << month << "." << year << endl;
  }
}
