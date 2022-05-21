#pragma once
#include "Session.h"
#include <string>

using namespace std;

class Gradesbook
{
	string gradesbookNum;
	Session* sessions[9];
	int sessionsQuantity;

	public:
		Gradesbook(string);

		int getSessionsQuantity();
		void print();
		int addSession(Session*);
		void enterSession();
		void editSession();
		void freeSessions();

		friend class File;
};

