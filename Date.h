#include <string>

using namespace std;

class Date {
  int day;
  int month;
  int year;
  
  public:
  Date();
  Date(string);
  Date(int, int, int);

  void setDate(string);
  void setDay(int);
  void setMonth(int);
  void setYear(int);

  int getDay();
  int getMonth();
  int getYear();

  void printDate();

  friend class Student;
};
