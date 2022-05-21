#include "Helpers.h"
#include <string>
#include <iostream>

using namespace std;

string Helpers::toLowerCase(string strValue) {
	string returnValue = "";

	for (int i = 0; i < strValue.length(); i++) {
        if ((int)strValue[i] > -65 && (int)strValue[i] < -32) {
            returnValue += char(int(strValue[i] + 32));
        }
        else if ((int)strValue[i] == -88) {
            returnValue += char(-72);
        }
        else {
            returnValue += tolower(strValue[i]);
        }
	}

	return returnValue;
}

void Helpers::showMessage(string message, int type) {
  switch (type) {
    case 1:
      cout << endl << "[INFO] " << message << endl;
      break;
    case 2:
      cout << endl << "[ERROR] " << message << endl;
      break;
  }
}

int Helpers::validateDay(int day, int month, int year) {
  int returnDay = -1;

  if (day < 1) {
    return returnDay;
  }

  if ((month == 1 && day <= 31) ||
      (month == 3 && day <= 31) ||
      (month == 4 && day <= 30) ||
      (month == 5 && day <= 31) ||
      (month == 6 && day <= 30) ||
      (month == 7 && day <= 31) ||
      (month == 8 && day <= 31) ||
      (month == 9 && day <= 30) ||
      (month == 10 && day <= 31) ||
      (month == 11 && day <= 30) ||
      (month == 12 && day <= 31)) {
    returnDay = day;
  } else if (month == 2) {
    if ((year % 4 == 0 && day <= 29) || day <= 28) {
      returnDay = day;
    }
  }

  return returnDay;
}

int Helpers::validateMonth(string month) {
    int returnMonth = -1;

    if (month == "Январь" ||
        month == "январь" ||
        month == "Янв" ||
        month == "янв" ||
        month == "January" ||
        month == "january" ||
        month == "Jan" ||
        month == "jan" ||
        month == "1" ||
        month == "01") {
        returnMonth = 1;
    }
    else if (month == "Февраль" ||
        month == "февраль" ||
        month == "Фев" ||
        month == "фев" ||
        month == "February" ||
        month == "february" ||
        month == "Feb" ||
        month == "feb" ||
        month == "2" ||
        month == "02") {
        returnMonth = 2;
    }
    else if (month == "Март" ||
        month == "март" ||
        month == "Мар" ||
        month == "мар" ||
        month == "March" ||
        month == "march" ||
        month == "Mar" ||
        month == "mar" ||
        month == "3" ||
        month == "03") {
        returnMonth = 3;
    }
    else if (month == "Апрель" ||
        month == "апрель" ||
        month == "Апр" ||
        month == "апр" ||
        month == "April" ||
        month == "april" ||
        month == "Apr" ||
        month == "apr" ||
        month == "4" ||
        month == "04") {
        returnMonth = 4;
    }
    else if (month == "Май" ||
        month == "май" ||
        month == "May" ||
        month == "may" ||
        month == "5" ||
        month == "05") {
        returnMonth = 5;
    }
    else if (month == "Июнь" ||
        month == "июнь" ||
        month == "June" ||
        month == "june" ||
        month == "6" ||
        month == "06") {
        returnMonth = 6;
    }
    else if (month == "Июль" ||
        month == "июль" ||
        month == "July" ||
        month == "july" ||
        month == "7" ||
        month == "07") {
        returnMonth = 7;
    }
    else if (month == "Август" ||
        month == "август" ||
        month == "Авг" ||
        month == "авг" ||
        month == "August" ||
        month == "august" ||
        month == "Aug" ||
        month == "aug" ||
        month == "8" ||
        month == "08") {
        returnMonth = 8;
    }
    else if (month == "Сентябрь" ||
        month == "сентябрь" ||
        month == "Сен" ||
        month == "сен" ||
        month == "September" ||
        month == "september" ||
        month == "Sep" ||
        month == "sep" ||
        month == "9" ||
        month == "09") {
        returnMonth = 9;
    }
    else if (month == "Октябрь" ||
        month == "октябрь" ||
        month == "Окт" ||
        month == "окт" ||
        month == "October" ||
        month == "october" ||
        month == "Oct" ||
        month == "oct" ||
        month == "10") {
        returnMonth = 10;
    }
    else if (month == "Ноябрь" ||
        month == "ноябрь" ||
        month == "Ноя" ||
        month == "ноя" ||
        month == "November" ||
        month == "november" ||
        month == "Nov" ||
        month == "nov" ||
        month == "11") {
        returnMonth = 11;
    }
    else if (month == "Декабрь" ||
        month == "декабрь" ||
        month == "Дек" ||
        month == "дек" ||
        month == "December" ||
        month == "december" ||
        month == "Dec" ||
        month == "dec" ||
        month == "12") {
        returnMonth = 12;
    }

    return returnMonth;
}

int Helpers::validateYear(string year) {
    for (int i = 0; i < year.length(); i++) {
        if (!((int)year[i] > 47 && (int)year[i] < 58)) {
            return -1;
        }
    }

    if (stoi(year) > 2030) {
        return -1;
    }

    if (stoi(year) < 10) {
        string yearStr = "200" + year;
        return stoi(yearStr);
    }
    else if (stoi(year) < 100) {
        string yearStr = "20" + year;
        return stoi(yearStr);
    }
    else {
        return stoi(year);
    }
}

int Helpers::validateStartStudyYear(int bornYear, int startStudyYear) {
    if (startStudyYear < bornYear + 6) {
        return -1;
    }

    return startStudyYear;
}

string* Helpers::validateDateString(string dateValue) {
    int startIndex = 0;
    int endIndex = dateValue.length() - 1;
    string dayValue = "";
    string monthValue = "";
    string yearValue = "";
    string* result = new string[3];

    for (int i = 0; i < dateValue.length(); i++) {
        if (!(((int)dateValue[i] > 47 && (int)dateValue[i] < 58) || ((int)dateValue[i] == 46) || ((int)dateValue[i] == 32))) {
            return NULL;
        }
    }

    for (int i = 0; i < dateValue.length(); i++) {
        if (dateValue[i] == ' ' || dateValue[i] == '.') {
            endIndex = i - 1;

            if (dayValue == "") {
                dayValue = dateValue.substr(startIndex, endIndex + 1 - startIndex);
            }
            else if (monthValue == "") {
                monthValue = dateValue.substr(startIndex, endIndex + 1 - startIndex);
            }
            else if (yearValue == "") {
                yearValue = dateValue.substr(startIndex, endIndex + 1 - startIndex);
            }

            startIndex = i + 1;
            endIndex = dateValue.length() - 1;
        }
    }

    if (yearValue == "") {
        yearValue = dateValue.substr(startIndex, endIndex);
    }

    if (validateMonth(monthValue) == -1) {
        return NULL;
    }
    else {
        monthValue = to_string(validateMonth(monthValue));
    }

    if (validateYear(yearValue) == -1) {
        return NULL;
    }
    else {
        yearValue = to_string(validateYear(yearValue));
    }

    if (validateDay(stoi(dayValue), stoi(monthValue), stoi(yearValue)) == -1) {
        return NULL;
    }
    else {
        dayValue = to_string(validateDay(stoi(dayValue), stoi(monthValue), stoi(yearValue)));
    }

    result[0] = dayValue;
    result[1] = monthValue;
    result[2] = yearValue;
    return result;
}

string Helpers::trim(string strValue) {
  string value = strValue;

  if (value == "") {
      return value;
  }

  int i = 0;

  while (value[i] == ' ' || value[i] == '\t') {
    i++;
  }

  if (i > 0) {
    value.erase(0, i);
  }

  i = value.length() - 1;

  while (value[i] == ' ' || value[i] == '\t') {
    i--;
  }

  if (i < value.length() - 1) {
    value.erase(i + 1);
  }

  return value;
}

string Helpers::validateName(string strValue) {
  string trimmedStr = trim(strValue);

  if (trimmedStr == "" || trimmedStr == " ") {
    return "";
  }

  for (int i = 0; i < trimmedStr.length(); i++) {
    if (!(((int)trimmedStr[i] > -65 && (int)trimmedStr[i] < 0) || (int)trimmedStr[i] == -88 || (int)trimmedStr[i] == -72 || (int)trimmedStr[i] == 45)) {
      return "";
    }
  }

  return trimmedStr;
}

string Helpers::validateInstitut(string institutValue) {
  string trimmedStr = trim(institutValue);
  
  if (trimmedStr == "" || trimmedStr == " ") {
    return "";
  }

  for (int i = 0; i < trimmedStr.length(); i++) {
    if (!(((int)trimmedStr[i] > -65 && (int)trimmedStr[i] < 0) || (int)trimmedStr[i] == 32 || (int)trimmedStr[i] == -88 || (int)trimmedStr[i] == -72)) {
      return "";
    }
  }

  return trimmedStr;
}

string Helpers::validateSex(string sexValue) {
  string trimmedStr = trim(sexValue);
  string returnSex = "";

  if (trimmedStr == "Мужской" ||
      trimmedStr == "мужской" ||
      trimmedStr == "Муж" ||
      trimmedStr == "муж" ||
      trimmedStr == "М" ||
      trimmedStr == "м" ||
      trimmedStr == "Male" ||
      trimmedStr == "male" ||
      trimmedStr == "M" ||
      trimmedStr == "m") {
    returnSex = "male";
  } else if (trimmedStr == "Женский" ||
      trimmedStr == "женский" ||
      trimmedStr == "Жен" ||
      trimmedStr == "жен" ||
      trimmedStr == "Ж" ||
      trimmedStr == "ж" ||
      trimmedStr == "Female" ||
      trimmedStr == "female" ||
      trimmedStr == "Fem" ||
      trimmedStr == "fem" ||
      trimmedStr == "F" ||
      trimmedStr == "f") {
    returnSex = "female";
  }

  return returnSex;
}

string Helpers::validateNumeric(string strValue) {
    if (strValue == "") {
        return "";
    }

    for (int i = 0; i < strValue.length(); i++) {
        if (!(int(strValue[i]) > 47 && int(strValue[i]) < 58)) {
            return "";
        }
    }

    return strValue;
}