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
		cout << endl << "Главное меню" << endl;
		cout << "Выберите действие:" << endl;
		cout << "1. Добавить студента" << endl;
		cout << "2. Изменить студента" << endl;
		cout << "3. Удалить студента" << endl;
		cout << "4. Вывести информацию о студенте" << endl;
		cout << "5. Работа с зачетной книжкой" << endl;
		cout << "6. Вывести группу студентов" << endl;
		cout << "7. Вывести всех студентов" << endl;
		cout << "8. Найти студента" << endl;
		cout << "0. Выйти" << endl;
		cout << "Ввод: ";
		cin >> mainMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(mainMenuPoint)) == "") {
			Helpers::showMessage("Такого пункта нет", 2);
			continue;
		}

		switch (stoi(mainMenuPoint)) {
		case 1:
			student->enterDataFull();
			file->write(student);
			break;
		case 2:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("Для выполнения данной функции выберите студента или создайте нового", 1);
				break;
			}

			studentEditMenu();
			break;
		case 3:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("Для выполнения данной функции выберите студента или создайте нового", 1);
				break;
			}

			file->removeStudent(student);
			Helpers::showMessage("Запись студента удалена", 1);
			break;
		case 4:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("Для выполнения данной функции выберите студента или создайте нового", 1);
				break;
			}

			student->printData();
			break;
		case 5:
			if (student->getInfoLine() == -1) {
				Helpers::showMessage("Для выполнения данной функции выберите студента или создайте нового", 1);
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
			Helpers::showMessage("До свидания", 1);
			return;
		default:
			Helpers::showMessage("Такого пункта нет", 2);
			break;
		}
	}
}

void Menu::studentEditMenu() {
	string studentEditMenuPoint = "- 1";

	while (1) {
		cout << endl << "Меню редактирования студента" << endl;
		cout << "Выберите что нужно изменить:" << endl;
		cout << "1. Имя" << endl;
		cout << "2. Фамилия" << endl;
		cout << "3. Отчество" << endl;
		cout << "4. Дата рождения" << endl;
		cout << "5. Год поступления" << endl;
		cout << "6. Название института" << endl;
		cout << "7. Название кафедры" << endl;
		cout << "8. Группа" << endl;
		cout << "9. Пол" << endl;
		cout << "0. Вернуться назад" << endl;
		cout << "Ввод: ";
		cin >> studentEditMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(studentEditMenuPoint)) == "") {
			Helpers::showMessage("Такого пункта нет", 2);
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
				Helpers::showMessage("Информация о студенте изменена", 1);
				return;
			case 0:
				return;
			default:
				Helpers::showMessage("Такого пункта нет", 2);
				break;
		}
	}
}

void Menu::studentFindMenu() {
	string studentFindMenuPoint = "-1";
	string studentFindValue = "";

	while (1) {
		cout << endl << "Меню поиска студента" << endl;
		cout << "По какому полю будет происходить поиск:" << endl;
		cout << "1. Имя" << endl;
		cout << "2. Фамилия" << endl;
		cout << "3. Отчество" << endl;
		cout << "4. Дата рождения" << endl;
		cout << "5. Год поступления" << endl;
		cout << "6. Название института" << endl;
		cout << "7. Название кафедры" << endl;
		cout << "8. Группа" << endl;
		cout << "9. Номер зачетной книжки" << endl;
		cout << "10. Пол" << endl;
		cout << "0. Вернуться назад" << endl;
		cout << "Ввод: ";
		cin >> studentFindMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(studentFindMenuPoint)) == "") {
			Helpers::showMessage("Такого пункта нет", 2);
			continue;
		}

		if (stoi(studentFindMenuPoint) == 0) {
			return;
		}

		cout << "Значение для поиска: ";
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
				Helpers::showMessage("Такого пункта нет", 2);
				break;
		}
	}
}

void Menu::groupFindMenu() {
	string findValue = "";

	cout << "Введите название группы: ";
	cin.ignore();
	getline(cin, findValue);
	file->findGroup(Helpers::toLowerCase(Helpers::trim(findValue)));
}

void Menu::gradesbookMenu() {
	gradesbook = new Gradesbook(student->getStudentNum());
	file->readOne(gradesbook, student->getInfoLine());
	string workWithGradesbookMenuPoint = "-1";

	while (1) {
		cout << endl << "Меню работы с зачетной книжкой:" << endl;

		if (gradesbook->getSessionsQuantity() != 9) {
			cout << "1. Добавить запись о " << gradesbook->getSessionsQuantity() + 1 << " сессии" << endl;
		}

		if (gradesbook->getSessionsQuantity()) {
			cout << "2. Изменить данные в зачетной книжке" << endl;
		}

		cout << "3. Вывести данные о зачетной книжке" << endl;
		cout << "0. Вернуться назад" << endl;
		cout << "Ввод: ";
		cin >> workWithGradesbookMenuPoint;

		if (Helpers::validateNumeric(Helpers::trim(workWithGradesbookMenuPoint)) == "") {
			Helpers::showMessage("Такого пункта нет", 2);
			continue;
		}

		switch (stoi(workWithGradesbookMenuPoint)) {
		case 1:
			if (gradesbook->getSessionsQuantity() != 9) {
				gradesbook->enterSession();
			}
			else {
				Helpers::showMessage("Такого пункта нет", 2);
			}
			break;
		case 2:
			if (gradesbook->getSessionsQuantity()) {
				gradesbook->editSession();
			}
			else {
				Helpers::showMessage("Такого пункта нет", 2);
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
			Helpers::showMessage("Такого пункта нет", 2);
			break;
		}
	}
}