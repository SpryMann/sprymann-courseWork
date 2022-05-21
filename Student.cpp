#include "Student.h"
#include "Helpers.h"
#include "File.h"
#include <iostream>

using namespace std;

Student::Student() {
	name = "";
	lastName = "";
	fatherName = "";
	bornDate.setDay(1);
	bornDate.setMonth(1);
	bornDate.setYear(2000);
	startStudy.setDay(0);
	startStudy.setMonth(0);
	startStudy.setYear(2006);
	institut = "";
	department = "";
	group = "";
	studentNum = "";
	sex = "male";
	infoLine = -1;
}

void Student::enterDataFull() {
	string enterName;
	string enterLastName;
	string enterFatherName;
	string enterBornDate;
	string enterStartStudy;
	string enterInstitut;
	string enterDepartment;
	string enterGroup;
	string enterStudentNum;
	string enterSex;

	cin.ignore();

	cout << endl << "Полный ввод данных" << endl;
	cout << "Имя: ";
	getline(cin, enterName);
	cout << "Фамилия: ";
	getline(cin, enterLastName);
	cout << "Отчество: ";
	getline(cin, enterFatherName);
	cout << "Дата рождения (в формате дд.мм.гггг или дд мм гггг): ";
	getline(cin, enterBornDate);
	cout << "Год поступления: ";
	getline(cin, enterStartStudy);
	cout << "Название института: ";
	getline(cin, enterInstitut);
	cout << "Кафедра: ";
	getline(cin, enterDepartment);
	cout << "Группа: ";
	getline(cin, enterGroup);
	cout << "Номер зачетной книжки (например, 21Б1295): ";
	cin >> enterStudentNum;
	cout << "Пол (мужской или женский): ";
	cin >> enterSex;

	cin.ignore();
	File* file = new File;

	while (1) {
		int isError = 0;

		if (Helpers::validateName(enterName) == "") {
			isError = 1;
			Helpers::showMessage("Неверно введено имя", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterName);
		}
		else {
			enterName = Helpers::validateName(enterName);
		}

		if (Helpers::validateName(enterLastName) == "") {
			isError = 1;
			Helpers::showMessage("Неверно введена фамилия", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterLastName);
		}
		else {
			enterLastName = Helpers::validateName(enterLastName);
		}

		if (Helpers::validateName(enterFatherName) == "") {
			isError = 1;
			Helpers::showMessage("Неверно введено отчество", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterFatherName);
		}
		else {
			enterFatherName = Helpers::validateName(enterFatherName);
		}

		if (Helpers::validateDateString(enterBornDate) == NULL) {
			isError = 1;
			Helpers::showMessage("Неверно введена дата рождения", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterBornDate);
		}

		if (Helpers::validateYear(Helpers::trim(enterStartStudy)) == -1) {
			isError = 1;
			Helpers::showMessage("Неверно введен год поступления", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterStartStudy);
		}
		else {
			enterStartStudy = to_string(Helpers::validateYear(Helpers::trim(enterStartStudy)));
		}

		if (Helpers::validateStartStudyYear(stoi(Helpers::validateDateString(enterBornDate)[2]), stoi(enterStartStudy)) == -1) {
			isError = 1;
			Helpers::showMessage("Для поступления в университет человеку должно быть не менее 6 лет", 2);
			cout << "Попробуйте изменить год поступления: ";
			getline(cin, enterStartStudy);
		}

		if (Helpers::validateInstitut(enterInstitut) == "") {
			isError = 1;
			Helpers::showMessage("Неверно введено название института", 2);
			cout << "Попробуйте еще раз: ";
			getline(cin, enterInstitut);
		}
		else {
			enterInstitut = Helpers::validateInstitut(enterInstitut);
		}

		if (file->isStudentNumExists(Helpers::trim(enterStudentNum)) == 1) {
			isError = 1;
			Helpers::showMessage("Студент с таким номером зачетной книжки уже существует", 2);
			cout << "Введите другой номер зачетной книжки: ";
			cin >> enterStudentNum;
		}
		else {
			enterStudentNum = Helpers::trim(enterStudentNum);
		}

		if (Helpers::validateSex(enterSex) == "") {
			isError = 1;
			Helpers::showMessage("Неверно введен пол", 2);
			cout << "Попробуйте еще раз: ";
			cin >> enterSex;
		}
		else {
			enterSex = Helpers::validateSex(enterSex);
		}

		if (!isError) {
			break;
		}
	}

	enterDepartment = Helpers::trim(enterDepartment);
	enterGroup = Helpers::trim(enterGroup);

	setName(enterName);
	setLastName(enterLastName);
	setFatherName(enterFatherName);
	setBornDate(enterBornDate);
	setStartStudy(enterStartStudy);
	setInstitut(enterInstitut);
	setDepartment(enterDepartment);
	setGroup(enterGroup);
	setStudentNum(enterStudentNum);
	setSex(enterSex);

	delete file;
}

void Student::enterDataPartial(int dataPoint) {
	if (dataPoint == 1) {
		string enterName;

		cout << "Введите имя: ";
		cin.ignore();
		getline(cin, enterName);

		while (1) {
			if (Helpers::validateName(enterName) == "") {
				Helpers::showMessage("Неверно введено имя", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterName);
			}
			else {
				enterName = Helpers::validateName(enterName);
				break;
			}
		}

		setName(enterName);
	} else if (dataPoint == 2) {
		string enterLastName;

		cout << "Введите фамилию: ";
		cin.ignore();
		getline(cin, enterLastName);

		while (1) {
			if (Helpers::validateName(enterLastName) == "") {
				Helpers::showMessage("Неверно введена фамилия", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterLastName);
			}
			else {
				enterLastName = Helpers::validateName(enterLastName);
				break;
			}
		}

		setLastName(enterLastName);
	} else if (dataPoint == 3) {
		string enterFatherName;

		cout << "Введите отчество: ";
		cin.ignore();
		getline(cin, enterFatherName);

		while (1) {
			if (Helpers::validateName(enterFatherName) == "") {
				Helpers::showMessage("Неверно введено отчество", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterFatherName);
			}
			else {
				enterFatherName = Helpers::validateName(enterFatherName);
				break;
			}
		}

		setFatherName(enterFatherName);
	} else if (dataPoint == 4) {
		string enterBornDate;

		cout << "Введите дату рождения (в формате дд.мм.гггг или через пробелы): ";
		cin.ignore();
		getline(cin, enterBornDate);

		while (1) {
			if (Helpers::validateDateString(enterBornDate) == NULL) {
				Helpers::showMessage("Неверно введена дата рождения", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterBornDate);
			}
			else {
				break;
			}
		}

		setBornDate(enterBornDate);
	} else if (dataPoint == 5) {
		string enterStartStudy;

		cout << "Введите год поступления: ";
		cin.ignore();
		getline(cin, enterStartStudy);

		while (1) {
			if (Helpers::validateYear(Helpers::trim(enterStartStudy)) == -1) {
				Helpers::showMessage("Неверно введен год поступления", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterStartStudy);
			}
			else {
				enterStartStudy = to_string(Helpers::validateYear(Helpers::trim(enterStartStudy)));
			}

			if (Helpers::validateStartStudyYear(bornDate.getYear(), stoi(enterStartStudy)) == -1) {
				Helpers::showMessage("Для поступления в университет человеку должно быть не менее 6 лет", 2);
				cout << "Измените год поступления: ";
				getline(cin, enterStartStudy);
			}
			else {
				break;
			}
		}

		setStartStudy(enterStartStudy);
	} else if (dataPoint == 6) {
		string enterInstitut;

		cout << "Введите название института: ";
		cin.ignore();
		getline(cin, enterInstitut);

		while (1) {
			if (Helpers::validateInstitut(enterInstitut) == "") {
				Helpers::showMessage("Неверно введено название института", 2);
				cout << "Попробуйте еще раз: ";
				getline(cin, enterInstitut);
			}
			else {
				enterInstitut = Helpers::validateInstitut(enterInstitut);
				break;
			}
		}

		setInstitut(enterInstitut);
	} else if (dataPoint == 7) {
		string enterDepartment;

		cout << "Введите название кафедры: ";
		cin.ignore();
		getline(cin, enterDepartment);

		enterDepartment = Helpers::trim(enterDepartment);
		setDepartment(enterDepartment);
	} else if (dataPoint == 8) {
		string enterGroup;

		cout << "Введите название группы: ";
		cin.ignore();
		getline(cin, enterGroup);

		enterGroup = Helpers::trim(enterGroup);
		setGroup(enterGroup);
	} else if (dataPoint == 9) {
		string enterSex;

		cout << "Введите пол: ";
		cin >> enterSex;

		while (1) {
			if (Helpers::validateSex(enterSex) == "") {
				Helpers::showMessage("Неверно введен пол", 2);
				cout << "Попробуйте еще раз: ";
				cin >> enterSex;
			}
			else {
				enterSex = Helpers::validateSex(enterSex);
				break;
			}
		}

		setSex(enterSex);
	}
}

void Student::printData() {
	Helpers::showMessage("Данные о студенте", 1);
	cout << "Имя: " << getName() << endl;
	cout << "Фамилия: " << getLastName() << endl;
	cout << "Отчество: " << getFatherName() << endl;
	cout << "Дата рождения: ";
	bornDate.printDate();
	cout << "Год поступления: ";
	startStudy.printDate();
	cout << "Название института: " << getInstitut() << endl;
	cout << "Кафедра: " << getDepartment() << endl;
	cout << "Группа: " << getGroup() << endl;
	cout << "Номер зачетной книжки: " << getStudentNum() << endl;
	
	if (getSex() == "female") {
		cout << "Пол: женский" << endl;
	}
	else {
		cout << "Пол: мужской" << endl;
	}
}

void Student::setName(string nameValue) {
	name = nameValue;
}

void Student::setLastName(string lastNameValue) {
	lastName = lastNameValue;
}

void Student::setFatherName(string fatherNameValue) {
	fatherName = fatherNameValue;
}

void Student::setBornDate(string bornDateValue) {
	string* result = Helpers::validateDateString(bornDateValue);
	bornDate.setDay(stoi(result[0]));
	bornDate.setMonth(stoi(result[1]));
	bornDate.setYear(stoi(result[2]));

	delete[] result;
}

void Student::setStartStudy(string startStudyValue) {
	startStudy.setYear(stoi(startStudyValue));
}

void Student::setInstitut(string institutValue) {
	institut = institutValue;
}

void Student::setDepartment(string departmentValue) {
	department = departmentValue;
}

void Student::setGroup(string groupValue) {
	group = groupValue;
}

void Student::setStudentNum(string studentNumValue) {
	studentNum = studentNumValue;
}

void Student::setSex(string sexValue) {
	sex = sexValue;
}

void Student::setInfoLine(int line) {
	infoLine = line;
}

string Student::getName() {
	return name;
}

string Student::getLastName() {
	return lastName;
}

string Student::getFatherName() {
	return fatherName;
}

Date Student::getBornDate() {
	return bornDate;
}

string Student::getBornDateStr() {
	string returnStr = to_string(bornDate.day) + "." + to_string(bornDate.month) + "." + to_string(bornDate.year);
	return returnStr;
}

Date Student::getStartStudy() {
	return startStudy;
}

string Student::getStartStudyStr() {
	return to_string(startStudy.getYear());
}

string Student::getInstitut() {
	return institut;
}

string Student::getDepartment() {
	return department;
}

string Student::getGroup() {
	return group;
}

string Student::getStudentNum() {
	return studentNum;
}

string Student::getSex() {
	return sex;
}

int Student::getInfoLine() {
	return infoLine;
}
