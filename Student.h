#pragma once
#include <string>
#include "Date.h"

class Student
{
	string name;
	string lastName;
	string fatherName;
	Date bornDate;
	Date startStudy;
	string institut;
	string department;
	string group;
	string studentNum;
	string sex;
	int infoLine;

	public:
		Student();

		void enterDataFull();
		void enterDataPartial(int);
		void printData();

		void setName(string);
		void setLastName(string);
		void setFatherName(string);
		void setBornDate(string);
		void setStartStudy(string);
		void setInstitut(string);
		void setDepartment(string);
		void setGroup(string);
		void setStudentNum(string);
		void setSex(string);
		void setInfoLine(int);

		string getName();
		string getLastName();
		string getFatherName();
		Date getBornDate();
		string getBornDateStr();
		Date getStartStudy();
		string getStartStudyStr();
		string getInstitut();
		string getDepartment();
		string getGroup();
		string getStudentNum();
		string getSex();
		int getInfoLine();
};

