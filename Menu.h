#pragma once
#include "Student.h"
#include "File.h"
#include "Gradesbook.h"

class Menu
{
	Student* student;
	File* file;
	Gradesbook* gradesbook;

	public:
		Menu();
		~Menu();
		void mainMenu();
		void studentEditMenu();
		void studentFindMenu();
		void groupFindMenu();
		void gradesbookMenu();
};

