#include "File.h"
#include "Student.h"
#include "Helpers.h"
#include <fstream>
#include <iostream>
#include <time.h>

using namespace std;

File::File() {
	name[0] = '\0';
	lastName[0] = '\0';
	fatherName[0] = '\0';
	bornDate[0] = '\0';
	startStudy[0] = '\0';
	institut[0] = '\0';
	department[0] = '\0';
	group[0] = '\0';
	studentNum[0] = '\0';
	sex[0] = '\0';

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 10; j++) {
			subjects[i][j][0] = '\0';
			marks[i][j][0] = '\0';
		}
	}

	lineSize = sizeof(name) + sizeof(lastName) + sizeof(fatherName) +
		sizeof(bornDate) + sizeof(startStudy) + sizeof(institut) +
		sizeof(department) + sizeof(group) + sizeof(studentNum) + sizeof(sex) + sizeof(subjects) + sizeof(marks) + 1;
}

void File::write(Student* student) {
	fstream dataFile("data.dat", ios_base::binary | ios_base::out | ios_base::in);

	if (!dataFile.is_open()) {
		ofstream dFile("data.dat", ios_base::binary | ios_base::out);
		dFile.close();
		dataFile.open("data.dat", ios_base::binary | ios_base::out | ios_base::in);
	}

	if (dataFile.is_open()) {
		int position = -1;
		int i = 0;

		while (!dataFile.eof()) {
			dataFile.seekg(lineSize * i, ios_base::beg);
			dataFile.read((char*) name, sizeof(name));

			if (name[0] == '\0') {
				position = lineSize * i;
				break;
			} else {
				i++;
				continue;
			}
		}

		dataFile.clear();

		if (position == -1) {
			dataFile.seekp(0, ios_base::end);
		} else {
			dataFile.seekp(position, ios_base::beg);
		}

		save(student);

		dataFile.write((char*)&name, sizeof(name));
		dataFile.write((char*)&lastName, sizeof(lastName));
		dataFile.write((char*)&fatherName, sizeof(fatherName));
		dataFile.write((char*)&bornDate, sizeof(bornDate));
		dataFile.write((char*)&startStudy, sizeof(startStudy));
		dataFile.write((char*)&institut, sizeof(institut));
		dataFile.write((char*)&department, sizeof(department));
		dataFile.write((char*)&group, sizeof(group));
		dataFile.write((char*)&studentNum, sizeof(studentNum));
		dataFile.write((char*)&sex, sizeof(sex));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				dataFile.write("\0", sizeof(subjects[i][j]));
				dataFile.write("\0", sizeof(marks[i][j]));
			}
		}

		dataFile.write("\n", 1);

		student->setInfoLine((int(dataFile.tellp()) - lineSize) / lineSize);
	}

	dataFile.close();
}

void File::edit(Student* student) {
	fstream dataFile("data.dat", ios_base::binary | ios_base::in | ios_base::out);

	if (dataFile.is_open()) {
		dataFile.seekp(lineSize * student->getInfoLine(), ios_base::beg);
		save(student);
		dataFile.write((char*)&name, sizeof(name));
		dataFile.write((char*)&lastName, sizeof(lastName));
		dataFile.write((char*)&fatherName, sizeof(fatherName));
		dataFile.write((char*)&bornDate, sizeof(bornDate));
		dataFile.write((char*)&startStudy, sizeof(startStudy));
		dataFile.write((char*)&institut, sizeof(institut));
		dataFile.write((char*)&department, sizeof(department));
		dataFile.write((char*)&group, sizeof(group));
		dataFile.write((char*)&studentNum, sizeof(studentNum));
		dataFile.write((char*)&sex, sizeof(sex));
	}

	dataFile.close();
}

void File::edit(Student* student, Gradesbook* gradesbook) {
	fstream dataFile("data.dat", ios_base::binary | ios_base::in | ios_base::out);

	if (dataFile.is_open()) {
		dataFile.seekp(lineSize * student->getInfoLine(), ios_base::beg);
		save(student, gradesbook);
		dataFile.write((char*)&name, sizeof(name));
		dataFile.write((char*)&lastName, sizeof(lastName));
		dataFile.write((char*)&fatherName, sizeof(fatherName));
		dataFile.write((char*)&bornDate, sizeof(bornDate));
		dataFile.write((char*)&startStudy, sizeof(startStudy));
		dataFile.write((char*)&institut, sizeof(institut));
		dataFile.write((char*)&department, sizeof(department));
		dataFile.write((char*)&group, sizeof(group));
		dataFile.write((char*)&studentNum, sizeof(studentNum));
		dataFile.write((char*)&sex, sizeof(sex));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				dataFile.write((char*)&subjects[i][j], sizeof(subjects[i][j]));
				dataFile.write((char*)&marks[i][j], sizeof(marks[i][j]));
			}
		}

		dataFile.write("\n", 1);
	}

	dataFile.close();
}

void File::removeStudent(Student* student) {
	fstream dataFile("data.dat", ios_base::binary | ios_base::in | ios_base::out);

	if (dataFile.is_open()) {
		dataFile.seekp(lineSize * student->getInfoLine(), ios_base::beg);
		dataFile.write("\0", sizeof(name));
		dataFile.write("\0", sizeof(lastName));
		dataFile.write("\0", sizeof(fatherName));
		dataFile.write("\0", sizeof(bornDate));
		dataFile.write("\0", sizeof(startStudy));
		dataFile.write("\0", sizeof(institut));
		dataFile.write("\0", sizeof(department));
		dataFile.write("\0", sizeof(group));
		dataFile.write("\0", sizeof(studentNum));
		dataFile.write("\0", sizeof(sex));

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				dataFile.write("\0", sizeof(subjects[i][j]));
				dataFile.write("\0", sizeof(marks[i][j]));
			}
		}

		student->setInfoLine(-1);
	}

	dataFile.close();
}

void File::readOne(Student* student, int line) {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);

	if (dataFile.is_open()) {
		dataFile.seekg(lineSize * line, ios_base::beg);
		dataFile.read((char*)name, sizeof(name));
		dataFile.read((char*)lastName, sizeof(lastName));
		dataFile.read((char*)fatherName, sizeof(fatherName));
		dataFile.read((char*)bornDate, sizeof(bornDate));
		dataFile.read((char*)startStudy, sizeof(startStudy));
		dataFile.read((char*)institut, sizeof(institut));
		dataFile.read((char*)department, sizeof(department));
		dataFile.read((char*)group, sizeof(group));
		dataFile.read((char*)studentNum, sizeof(studentNum));
		dataFile.read((char*)sex, sizeof(sex));

		if (name[0] == '\0') {
			student = NULL;
			return;
		}

		student->setName(string(name));
		student->setLastName(string(lastName));
		student->setFatherName(string(fatherName));
		student->setBornDate(string(bornDate));
		student->setStartStudy(string(startStudy));
		student->setInstitut(string(institut));
		student->setDepartment(string(department));
		student->setGroup(string(group));
		student->setStudentNum(string(studentNum));
		student->setSex(string(sex));
		student->setInfoLine(line);
	}

	dataFile.close();
}

void File::readOne(Gradesbook* gradesbook, int line) {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);

	if (dataFile.is_open()) {
		dataFile.seekg(lineSize * line, ios_base::beg);
		dataFile.seekg((sizeof(name) + sizeof(lastName) + sizeof(fatherName) + sizeof(bornDate) +
			sizeof(startStudy) + sizeof(institut) + sizeof(department) + sizeof(group) +
			sizeof(studentNum) + sizeof(sex)), ios_base::cur);

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 10; j++) {
				dataFile.read((char*)subjects[i][j], sizeof(subjects[i][j]));
				dataFile.read((char*)marks[i][j], sizeof(marks[i][j]));
			}
		}

		for (int i = 0; i < 9; i++) {
			if (subjects[i][0][0] == '\0') {
				break;
			}

			Session* session = new Session;

			for (int j = 0; j < 10; j++) {
				if (subjects[i][j][0] == '\0') {
					break;
				}

				Subject* subject = new Subject(string(subjects[i][j]), atoi(marks[i][j]));
				session->addSubject(subject);
			}

			gradesbook->addSession(session);
		}
	}

	dataFile.close();
}

void File::readAll() {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);
	Student student;

	if (dataFile.is_open()) {
		dataFile.seekg(0, ios_base::end);
		int size = int(dataFile.tellg());
		dataFile.seekg(0, ios_base::beg);
		int line = 0;

		cout << endl << "Список студентов: " << endl;

		while (line < (size / lineSize)) {
			dataFile.seekg(lineSize * line, ios_base::beg);
			dataFile.read((char*)name, sizeof(name));

			if (name[0] == '\0') {
				line++;
				continue;
			}

			dataFile.read((char*)lastName, sizeof(lastName));
			dataFile.read((char*)fatherName, sizeof(fatherName));
			dataFile.read((char*)bornDate, sizeof(bornDate));
			dataFile.read((char*)startStudy, sizeof(startStudy));
			dataFile.read((char*)institut, sizeof(institut));
			dataFile.read((char*)department, sizeof(department));
			dataFile.read((char*)group, sizeof(group));
			dataFile.read((char*)studentNum, sizeof(studentNum));
			dataFile.read((char*)sex, sizeof(sex));

			student.setName(string(name));
			student.setLastName(string(lastName));
			student.setFatherName(string(fatherName));
			student.setBornDate(string(bornDate));
			student.setStartStudy(string(startStudy));
			student.setInstitut(string(institut));
			student.setDepartment(string(department));
			student.setGroup(string(group));
			student.setStudentNum(string(studentNum));
			student.setSex(string(sex));
			cout << student.getLastName() << " " << student.getName() << " " << student.getFatherName() << " " << student.getGroup() << " " << student.getStudentNum() << endl;
			line++;
		}		
	}
	else {
		Helpers::showMessage("Пока записей о студентах нет", 1);
	}

	dataFile.close();
}

void File::find(Student* student, string findValue, int findPoint) {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);

	if (dataFile.is_open()) {
		dataFile.seekg(0, ios_base::end);
		int size = int(dataFile.tellg());
		dataFile.seekg(0, ios_base::beg);
		int line = 0;
		int foundStudentsLines[10];
		int foundStudentsCurrent = 0;
		int foundStudentsQuantity = 0;

		while (line < (size / lineSize)) {
			dataFile.seekg(lineSize * line, ios_base::beg);
			dataFile.read((char*)name, sizeof(name));

			if (name[0] == '\0') {
				line++;
				continue;
			}

			Student* foundStudent = new Student;
			int isFound = 0;
			readOne(foundStudent, line);

			switch (findPoint) {
				case 1:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getName())) {
						isFound = 1;
					}
					break;
				case 2:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getLastName())) {
						isFound = 1;
					}
					break;
				case 3:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getFatherName())) {
						isFound = 1;
					}
					break;
				case 4:
				{
					string* dateParts = Helpers::validateDateString(Helpers::trim(findValue));
					if (dateParts != NULL && Helpers::toLowerCase(dateParts[0] + "." + dateParts[1] + "." + dateParts[2]) == Helpers::toLowerCase(foundStudent->getBornDateStr())) {
						isFound = 1;
					}
				}
					break;
				case 5:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getStartStudyStr())) {
						isFound = 1;
					}
					break;
				case 6:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getInstitut())) {
						isFound = 1;
					}
					break;
				case 7:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getDepartment())) {
						isFound = 1;
					}
					break;
				case 8:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getGroup())) {
						isFound = 1;
					}
					break;
				case 9:
					if (Helpers::toLowerCase(Helpers::trim(findValue)) == Helpers::toLowerCase(foundStudent->getStudentNum())) {
						isFound = 1;
					}
					break;
				case 10:
					if (Helpers::toLowerCase(Helpers::validateSex(findValue)) == Helpers::toLowerCase(foundStudent->getSex())) {
						isFound = 1;
					}
					break;
			}

			if (isFound) {
				foundStudentsQuantity++;
				Helpers::showMessage("Найдена подходящая запись: " + to_string(foundStudentsQuantity) + ". " + foundStudent->getLastName() + " " + foundStudent->getName() + " " + foundStudent->getFatherName() + " " + foundStudent->getGroup() + " " + foundStudent->getStudentNum(), 1);
				foundStudentsLines[foundStudentsCurrent] = line;
				foundStudentsCurrent++;
			}

			if (foundStudentsCurrent == 10) {
				string chooseOneStudentPoint = "-1";

				Helpers::showMessage("Найдено 10 подходящих записей", 1);
				cout << "Что нужно сделать:" << endl;
				cout << "1-10. Выбрать студента" << endl;
				cout << "11. Следующая страница" << endl;
				cout << "0. Вернуться назад" << endl;
				cout << "Ввод: ";
				cin >> chooseOneStudentPoint;

				if (Helpers::validateNumeric(Helpers::trim(chooseOneStudentPoint)) == "") {
					Helpers::showMessage("Такого пункта нет", 2);
					return;
				}

				switch (stoi(chooseOneStudentPoint)) {
					case 1:
					case 2:
					case 3:
					case 4:
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
					case 10:
						readOne(student, foundStudentsLines[stoi(chooseOneStudentPoint) - 1]);
						Helpers::showMessage("Студент выбран", 2);
						return;
					case 11:
						foundStudentsCurrent = 0;
						break;
					case 0:
						return;
					default:
						Helpers::showMessage("Такого пункта нет", 2);
						return;
				}
			}

			line++;
			delete foundStudent;
		}

		if (foundStudentsCurrent) {
			string chooseOneStudentPoint = "-1";

			Helpers::showMessage("Найдено подходящих записей: " + to_string(foundStudentsCurrent), 1);
			cout << "Что нужно сделать:" << endl;

			if (foundStudentsCurrent == 1) {
				cout << "1. Выбрать студента" << endl;
			} else {
				cout << "1-" << foundStudentsCurrent << ". Выбрать студента" << endl;

			}

			cout << "0. Закрыть" << endl;
			cout << "Ввод: ";
			cin >> chooseOneStudentPoint;

			if (Helpers::validateNumeric(Helpers::trim(chooseOneStudentPoint)) == "") {
				Helpers::showMessage("Такого пункта нет", 2);
				return;
			}

			if (stoi(chooseOneStudentPoint) > 0 && stoi(chooseOneStudentPoint) <= foundStudentsCurrent) {
				readOne(student, foundStudentsLines[stoi(chooseOneStudentPoint) - 1]);
				Helpers::showMessage("Студент выбран", 1);
				return;
			} else {
				Helpers::showMessage("Такого пункта нет", 2);
				return;
			}
		} else {
			Helpers::showMessage("Больше записей не найдено", 1);
		}

		if (foundStudentsQuantity == 0) {
			Helpers::showMessage("По данному запросу студенты не найдены", 1);
		}
	}

	dataFile.close();
}

void File::writeGroup() {
	ofstream groupFile("group.dat", ios_base::binary | ios_base::out | ios_base::app);

	if (groupFile.is_open()) {
		groupFile.write((char*)&name, sizeof(name));
		groupFile.write((char*)&lastName, sizeof(lastName));
		groupFile.write((char*)&fatherName, sizeof(fatherName));
		groupFile.write((char*)&bornDate, sizeof(bornDate));
		groupFile.write((char*)&startStudy, sizeof(startStudy));
		groupFile.write((char*)&institut, sizeof(institut));
		groupFile.write((char*)&department, sizeof(department));
		groupFile.write((char*)&group, sizeof(group));
		groupFile.write((char*)&studentNum, sizeof(studentNum));
		groupFile.write((char*)&sex, sizeof(sex));
		groupFile.write("\n", 1);
	}

	groupFile.close();
}

void File::findGroup(string groupValue) {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);
	
	if (dataFile.is_open()) {
		dataFile.seekg(0, ios_base::end);
		int size = (int) dataFile.tellg();
		dataFile.seekg(0, ios_base::beg);
		int i = 0;
		int girls[30];
		int girlsQuantity = 0;
		int boys[30];
		int boysQuantity = 0;

		while (i * lineSize < size) {
			int isFound = 0;
			dataFile.seekg(lineSize * i, ios_base::beg);
			dataFile.seekg(lineSize - sizeof(subjects) - sizeof(marks) - 51, ios_base::cur);
			dataFile.read((char*)group, sizeof(group));

			if (groupValue == Helpers::toLowerCase(string(group))) {
				isFound = 1;
			}

			if (isFound) {
				dataFile.seekg(20, ios_base::cur);
				dataFile.read((char*)sex, sizeof(sex));

				if (string(sex) == "female") {
					girls[girlsQuantity] = i;
					girlsQuantity++;
				}
				else {
					boys[boysQuantity] = i;
					boysQuantity++;
				}
			}

			i++;
		}


		if (girlsQuantity + boysQuantity > 0) {
			Student* student = new Student;
			ofstream groupFile("group.dat", ios_base::binary | ios_base::trunc | ios_base::out);
			groupFile.close();

			if (girlsQuantity) {
				for (int i = 0; i < girlsQuantity; i++) {
					readOne(student, girls[i]);
					save(student);
					writeGroup();
				}
			}

			if (boysQuantity) {
				for (int i = 0; i < boysQuantity; i++) {
					readOne(student, boys[i]);
					save(student);
					writeGroup();
				}
			}

			delete student;

			sortGroup();
			readGroup(girlsQuantity, boysQuantity);
		}
		else {
			Helpers::showMessage("Студенты из такой группы не найдены", 1);
		}
	}

	dataFile.close();
}

void File::sortGroup() {
	fstream file("group.dat", ios_base::binary | ios_base::in | ios_base::out);

	if (file.is_open()) {
		file.seekg(0, ios_base::end);
		int size = (int) file.tellg();
		file.seekg(0, ios_base::beg);
		int i = 0;
		char name1[20];
		char lastName1[20];
		char fatherName1[20];
		char bornDate1[20];
		char startStudy1[10];
		char institut1[100];
		char department1[20];
		char group1[20];
		char studentNum1[20];
		char sex1[10];
		char name2[20];
		char lastName2[20];
		char fatherName2[20];
		char bornDate2[20];
		char startStudy2[10];
		char institut2[100];
		char department2[20];
		char group2[20];
		char studentNum2[20];
		char sex2[10];

		while (i < size / (lineSize - sizeof(subjects) - sizeof(marks))) {
			int hasLess = 0;
			int j = i + 1;

			while (j < size / (lineSize - sizeof(subjects) - sizeof(marks))) {
				file.seekg((lineSize - sizeof(subjects) - sizeof(marks)) * i, ios_base::beg);
				file.read((char*)name1, sizeof(name1));
				file.read((char*)lastName1, sizeof(lastName1));
				file.read((char*)fatherName1, sizeof(fatherName1));
				file.read((char*)bornDate1, sizeof(bornDate1));
				file.read((char*)startStudy1, sizeof(startStudy1));
				file.read((char*)institut1, sizeof(institut1));
				file.read((char*)department1, sizeof(department1));
				file.read((char*)group1, sizeof(group1));
				file.read((char*)studentNum1, sizeof(studentNum1));
				file.read((char*)sex1, sizeof(sex1));

				file.seekg((lineSize - sizeof(subjects) - sizeof(marks)) * j, ios_base::beg);
				file.read((char*)name2, sizeof(name2));
				file.read((char*)lastName2, sizeof(lastName2));
				file.read((char*)fatherName2, sizeof(fatherName2));
				file.read((char*)bornDate2, sizeof(bornDate2));
				file.read((char*)startStudy2, sizeof(startStudy2));
				file.read((char*)institut2, sizeof(institut2));
				file.read((char*)department2, sizeof(department2));
				file.read((char*)group2, sizeof(group2));
				file.read((char*)studentNum2, sizeof(studentNum2));
				file.read((char*)sex2, sizeof(sex2));

				if (strcmp(lastName1, lastName2) == 1 && string(sex1) == string(sex2)) {
					file.seekp((lineSize - sizeof(subjects) - sizeof(marks)) * i, ios_base::beg);
					file.write((char*)&name2, sizeof(name2));
					file.write((char*)&lastName2, sizeof(lastName2));
					file.write((char*)&fatherName2, sizeof(fatherName2));
					file.write((char*)&bornDate2, sizeof(bornDate2));
					file.write((char*)&startStudy2, sizeof(startStudy2));
					file.write((char*)&institut2, sizeof(institut2));
					file.write((char*)&department2, sizeof(department2));
					file.write((char*)&group2, sizeof(group2));
					file.write((char*)&studentNum2, sizeof(studentNum2));
					file.write((char*)&sex2, sizeof(sex2));
					file.write("\n", 1);

					file.seekg((lineSize - sizeof(subjects) - sizeof(marks)) * j, ios_base::beg);
					file.write((char*)&name1, sizeof(name1));
					file.write((char*)&lastName1, sizeof(lastName1));
					file.write((char*)&fatherName1, sizeof(fatherName1));
					file.write((char*)&bornDate1, sizeof(bornDate1));
					file.write((char*)&startStudy1, sizeof(startStudy1));
					file.write((char*)&institut1, sizeof(institut1));
					file.write((char*)&department1, sizeof(department1));
					file.write((char*)&group1, sizeof(group1));
					file.write((char*)&studentNum1, sizeof(studentNum1));
					file.write((char*)&sex1, sizeof(sex1));
					file.write("\n", 1);

					hasLess = 1;
					break;
				}

				j++;
			}

			if (!hasLess) {
				i++;
			}
		}
	}

	file.close();
}

void File::readGroup(int girlsQuantity, int boysQuantity) {
	ifstream file("group.dat", ios_base::binary | ios_base::in);

	if (file.is_open()) {
		if (girlsQuantity) {
			cout << endl << "Женская часть:" << endl;
			for (int i = 0; i < girlsQuantity; i++) {
				file.seekg((lineSize - sizeof(subjects) - sizeof(marks)) * i, ios_base::beg);
				file.read((char*)name, sizeof(name));
				file.read((char*)lastName, sizeof(lastName));
				file.read((char*)fatherName, sizeof(fatherName));
				file.read((char*)bornDate, sizeof(bornDate));
				file.read((char*)startStudy, sizeof(startStudy));
				file.read((char*)institut, sizeof(institut));
				file.read((char*)department, sizeof(department));
				file.read((char*)group, sizeof(group));
				file.read((char*)studentNum, sizeof(studentNum));
				file.read((char*)sex, sizeof(sex));
				cout << i + 1 << ". " << name << " " << lastName << " " << studentNum << endl;
			}
		}

		if (boysQuantity) {
			cout << endl << "Мужская часть:" << endl;
			for (int i = girlsQuantity; i < girlsQuantity + boysQuantity; i++) {
				file.seekg((lineSize - sizeof(subjects) - sizeof(marks)) * i, ios_base::beg);
				file.read((char*)name, sizeof(name));
				file.read((char*)lastName, sizeof(lastName));
				file.read((char*)fatherName, sizeof(fatherName));
				file.read((char*)bornDate, sizeof(bornDate));
				file.read((char*)startStudy, sizeof(startStudy));
				file.read((char*)institut, sizeof(institut));
				file.read((char*)department, sizeof(department));
				file.read((char*)group, sizeof(group));
				file.read((char*)studentNum, sizeof(studentNum));
				file.read((char*)sex, sizeof(sex));
				cout << i + 1 << ". " << name << " " << lastName << " " << studentNum << endl;
			}
		}
	}

	file.close();
	remove("group.dat");
}

int File::isStudentNumExists(string studentNumValue) {
	ifstream dataFile("data.dat", ios_base::binary | ios_base::in);
	int isExists = 0;

	if (dataFile.is_open()) {
		int i = 0;

		while (!dataFile.eof()) {
			dataFile.seekg(lineSize * i, ios_base::beg);
			dataFile.seekg(lineSize - sizeof(subjects) - sizeof(marks) - 31, ios_base::cur);
			dataFile.read((char*)studentNum, sizeof(studentNum));

			if (Helpers::toLowerCase(string(studentNum)) == Helpers::toLowerCase(studentNumValue)) {
				isExists = 1;
				return isExists;
			}

			i++;
		}
	}

	dataFile.close();
	return isExists;
}

int File::isFileExists(string fileName) {
  ifstream file(fileName);

  if (file) {
    file.close();
    return 1;
  }

  return 0;
}

void File::encrypt() {
  srand(time(NULL));
  char password[65] = "\0";
  string alphabet = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  for (int i = 0; i < 64; i++) {
	  password[i] = alphabet[rand() % alphabet.length()];
  }

  password[64] = '\0';

  string command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -pbkdf2 -salt -in data.dat -out data.enc -pass pass:";
  command += password;
  system(command.c_str());

  if (remove("data.dat") != 0) {
    Helpers::showMessage("Невозможно удалить файл data.dat", 2);
  }

  ofstream file("key.txt", ios_base::binary);
  file.write((char*)&password, sizeof(password));
  file.close();

  command = "openssl\\bin\\openssl.exe pkeyutl -encrypt -pubin -inkey rsa.public -in key.txt -out key.enc";
  system(command.c_str());

  if (remove("key.txt") != 0) {
    Helpers::showMessage("Невозможно удалить файл key.txt", 2);
  }
}

void File::decrypt() {
  string command = "openssl\\bin\\openssl.exe pkeyutl -decrypt -inkey rsa.private -in key.enc -out key.txt";
  system(command.c_str());

  if (remove("key.enc") != 0) {
    Helpers::showMessage("Невозможно удалить файл key.txt.enc", 2);
  }

  char password[65] = "\0";
  ifstream file("key.txt", ios_base::binary);
  file.read((char*)password, sizeof(password));
  file.close();

  if (remove("key.txt") != 0) {
    Helpers::showMessage("Невозможно удалить файл key.txt", 2);
  }

  command = "openssl\\bin\\openssl.exe enc -aes-256-cbc -pbkdf2 -d -in data.enc -out data.dat -pass pass:";
  command += password;
  system(command.c_str());

  if (remove("data.enc") != 0) {
    Helpers::showMessage("Невозможно удалить файл data.dat.enc", 2);
  }
}

void File::save(Student* student) {
	strcpy_s(name, 20, student->getName().substr(0, sizeof(name) - 1).c_str());
	strcpy_s(lastName, 20, student->getLastName().substr(0, sizeof(lastName) - 1).c_str());
	strcpy_s(fatherName, 20, student->getFatherName().substr(0, sizeof(fatherName) - 1).c_str());
	strcpy_s(bornDate, 20, student->getBornDateStr().substr(0, sizeof(bornDate) - 1).c_str());
	strcpy_s(startStudy, 10, student->getStartStudyStr().substr(0, sizeof(startStudy) - 1).c_str());
	strcpy_s(institut, 100, student->getInstitut().substr(0, sizeof(institut) - 1).c_str());
	strcpy_s(department, 20, student->getDepartment().substr(0, sizeof(department) - 1).c_str());
	strcpy_s(group, 20, student->getGroup().substr(0, sizeof(group) - 1).c_str());
	strcpy_s(studentNum, 20, student->getStudentNum().substr(0, sizeof(studentNum) - 1).c_str());
	strcpy_s(sex, 10, student->getSex().substr(0, sizeof(sex) - 1).c_str());
}

void File::save(Student* student, Gradesbook* gradesbook) {
	strcpy_s(name, 20, student->getName().substr(0, sizeof(name) - 1).c_str());
	strcpy_s(lastName, 20, student->getLastName().substr(0, sizeof(lastName) - 1).c_str());
	strcpy_s(fatherName, 20, student->getFatherName().substr(0, sizeof(fatherName) - 1).c_str());
	strcpy_s(bornDate, 20, student->getBornDateStr().substr(0, sizeof(bornDate) - 1).c_str());
	strcpy_s(startStudy, 10, student->getStartStudyStr().substr(0, sizeof(startStudy) - 1).c_str());
	strcpy_s(institut, 100, student->getInstitut().substr(0, sizeof(institut) - 1).c_str());
	strcpy_s(department, 20, student->getDepartment().substr(0, sizeof(department) - 1).c_str());
	strcpy_s(group, 20, student->getGroup().substr(0, sizeof(group) - 1).c_str());
	strcpy_s(studentNum, 20, student->getStudentNum().substr(0, sizeof(studentNum) - 1).c_str());
	strcpy_s(sex, 10, student->getSex().substr(0, sizeof(sex) - 1).c_str());

	for (int i = 0; i < gradesbook->getSessionsQuantity(); i++) {
		for (int j = 0; j < gradesbook->sessions[i]->getSubjectsQuantity(); j++) {
			strcpy_s(subjects[i][j], 100, gradesbook->sessions[i]->subjects[j]->getSubjectName().substr(0, sizeof(subjects[i][j]) - 1).c_str());
			strcpy_s(marks[i][j], 10, to_string(gradesbook->sessions[i]->subjects[j]->getSubjectMark()).substr(0, sizeof(marks[i][j]) - 1).c_str());
		}
	}
}
