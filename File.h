#pragma once
#include "Student.h"
#include "Gradesbook.h"

class File
{
	char name[20];
	char lastName[20];
	char fatherName[20];
	char bornDate[20];
	char startStudy[10];
	char institut[100];
	char department[20];
	char group[20];
	char studentNum[20];
	char sex[10];
	int lineSize;
	char subjects[9][10][100];
	char marks[9][10][10];

	public:
		File();
		void write(Student*);
		void readOne(Student*, int);
		void readOne(Gradesbook*, int);
		void readAll();
		void edit(Student*);
		void edit(Student*, Gradesbook*);
		void removeStudent(Student*);
		void find(Student*, string, int);
		void writeGroup();
		void findGroup(string);
		void sortGroup();
		void readGroup(int, int);
		int isStudentNumExists(string);
		static int isFileExists(string);
		static void encrypt();
		static void decrypt();


	private:
		void save(Student*);
		void save(Student*, Gradesbook*);
};

