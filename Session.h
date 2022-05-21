#pragma once
#include "Subject.h"
#include <string>

using namespace std;

class Session
{
	Subject* subjects[10];
	int subjectsCurrentQuantity = 0;

	public:
		int getSubjectsQuantity();
		Subject* getCertainSubject(int);
		int addSubject(Subject*);
		int isSubjectExists(string);

	friend class File;
};

