#pragma once
#include <string>

using namespace std;

class Subject
{
	string name;
	int mark;

	public:
		Subject();
		Subject(string, int);

		string getSubjectName();
		int getSubjectMark();

		friend class Session;
};

