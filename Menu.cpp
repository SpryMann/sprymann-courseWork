#include "Menu.h"
#include "Helpers.h"
#include "Student.h"
#include <iostream>

using namespace std;

Menu::Menu() {
	student = new Student;
	file = new File;
	gradesbook = NULL;
}

Menu::~Menu() {
	delete student;
	delete file;
}

void Menu::mainMenu() {
	string mainMenuPoint = "-1";

	while (1) {
		cout << endl << "������� ����" << endl;
		cout << "�������� ��������:" << endl;
		cout << "1. �������� ��������" << endl;
		cout << "2. �������� ��������" << endl;
		cout << "3. ������� ��������" << endl;
		cout << "4. ������� ���������� � ��������" << endl;
		cout << "5. ������ � �������� �������" << endl;
		cout << "6. ������� ������ ���������" << endl;
		cout << "7. ������� ���� ���������" << endl;
		cout << "8. ����� ��������" << endl;
		cout << "0. �����" << endl;
		cout << "����: ";
		cin >> mainMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(mainMenuPoint)) == "") {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}

		switch (stoi(mainMenuPoint)) {
		case 1:
			student->enterDataFull();
			file->write(student);
			break;
		case 2:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("��� ���������� ������ ������� �������� �������� ��� �������� ������", 1);
				break;
			}

			studentEditMenu();
			break;
		case 3:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("��� ���������� ������ ������� �������� �������� ��� �������� ������", 1);
				break;
			}

			file->removeStudent(student);
			Helpers::showMessage("������ �������� �������", 1);
			break;
		case 4:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("��� ���������� ������ ������� �������� �������� ��� �������� ������", 1);
				break;
			}

			student->printData();
			break;
		case 5:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("��� ���������� ������ ������� �������� �������� ��� �������� ������", 1);
				break;
			}

			gradesbookMenu();
			break;
		case 6:
			groupFindMenu();
			break;
		case 7:
			file->readAll();
			break;
		case 8:
			studentFindMenu();
			break;
		case 0:
			Helpers::showMessage("�� ��������", 1);
			return;
		default:
			Helpers::showMessage("������ ������ ���", 2);
			break;
		}
	}
}

void Menu::studentEditMenu() {
	string studentEditMenuPoint = "- 1";

	while (1) {
		cout << endl << "���� �������������� ��������" << endl;
		cout << "�������� ��� ����� ��������:" << endl;
		cout << "1. ���" << endl;
		cout << "2. �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. ���� ��������" << endl;
		cout << "5. ��� �����������" << endl;
		cout << "6. �������� ���������" << endl;
		cout << "7. �������� �������" << endl;
		cout << "8. ������" << endl;
		cout << "9. ���" << endl;
		cout << "0. ��������� �����" << endl;
		cout << "����: ";
		cin >> studentEditMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(studentEditMenuPoint)) == "") {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}

		if (stoi(studentEditMenuPoint) == 0) {
			return;
		}

		switch (stoi(studentEditMenuPoint)) {
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				student->enterDataPartial(stoi(studentEditMenuPoint));
				file->edit(student);
				Helpers::showMessage("���������� � �������� ��������", 1);
				return;
			case 0:
				return;
			default:
				Helpers::showMessage("������ ������ ���", 2);
				break;
		}
	}
}

void Menu::studentFindMenu() {
	string studentFindMenuPoint = "-1";
	string studentFindValue = "";

	while (1) {
		cout << endl << "���� ������ ��������" << endl;
		cout << "�� ������ ���� ����� ����������� �����:" << endl;
		cout << "1. ���" << endl;
		cout << "2. �������" << endl;
		cout << "3. ��������" << endl;
		cout << "4. ���� ��������" << endl;
		cout << "5. ��� �����������" << endl;
		cout << "6. �������� ���������" << endl;
		cout << "7. �������� �������" << endl;
		cout << "8. ������" << endl;
		cout << "9. ����� �������� ������" << endl;
		cout << "10. ���" << endl;
		cout << "0. ��������� �����" << endl;
		cout << "����: ";
		cin >> studentFindMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(studentFindMenuPoint)) == "") {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}

		if (stoi(studentFindMenuPoint) == 0) {
			return;
		}

		cout << "�������� ��� ������: ";
		cin.ignore();
		getline(cin, studentFindValue);

		switch (stoi(studentFindMenuPoint)) {
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
				file->find(student, studentFindValue, stoi(studentFindMenuPoint));
				return;
			case 0:
				return;
			default:
				Helpers::showMessage("������ ������ ���", 2);
				break;
		}
	}
}

void Menu::groupFindMenu() {
	string findValue = "";

	cout << "������� �������� ������: ";
	cin.ignore();
	getline(cin, findValue);
	file->findGroup(Helpers::toLowerCase(Helpers::trim(findValue)));
}

void Menu::gradesbookMenu() {
	gradesbook = new Gradesbook(student->getStudentNum());
	file->readOne(gradesbook, student->getInfoLine());
	string workWithGradesbookMenuPoint = "-1";

	while (1) {
		cout << endl << "���� ������ � �������� �������:" << endl;

		if (gradesbook->getSessionsQuantity() != 9) {
			cout << "1. �������� ������ � " << gradesbook->getSessionsQuantity() + 1 << " ������" << endl;
		}

		if (gradesbook->getSessionsQuantity()) {
			cout << "2. �������� ������ � �������� ������" << endl;
		}

		cout << "3. ������� ������ � �������� ������" << endl;
		cout << "0. ��������� �����" << endl;
		cout << "����: ";
		cin >> workWithGradesbookMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(workWithGradesbookMenuPoint)) == "") {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}

		switch (stoi(workWithGradesbookMenuPoint)) {
		case 1:
			if (gradesbook->getSessionsQuantity() != 9) {
				gradesbook->enterSession();
			}
			else {
				Helpers::showMessage("������ ������ ���", 2);
			}
			break;
		case 2:
			if (gradesbook->getSessionsQuantity()) {
				gradesbook->editSession();
			}
			else {
				Helpers::showMessage("������ ������ ���", 2);
			}
			break;
		case 3:
			gradesbook->print();
			break;
		case 0:
			file->edit(student, gradesbook);
			gradesbook->freeSessions();
			delete gradesbook;
			return;
		default:
			Helpers::showMessage("������ ������ ���", 2);
			break;
		}
	}
}