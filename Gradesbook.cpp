#include "Gradesbook.h"
#include "Helpers.h"
#include <string>
#include <iostream>

using namespace std;

Gradesbook::Gradesbook(string studentNum) {
	gradesbookNum = studentNum;
	sessionsQuantity = 0;
}

int Gradesbook::getSessionsQuantity() {
	return sessionsQuantity;
}

void Gradesbook::print() {
	for (int i = 0; i < getSessionsQuantity(); i++) {
		cout << endl << i + 1 << " ������" << endl;

		for (int j = 0; j < (*sessions[i]).getSubjectsQuantity(); j++) {
			cout << (*sessions[i]).getCertainSubject(j)->getSubjectName() << ": " << (*sessions[i]).getCertainSubject(j)->getSubjectMark() << endl;
		}
	}
}

int Gradesbook::addSession(Session* session) {
	int isAdded = 0;

	if (getSessionsQuantity() != 9) {
		sessions[sessionsQuantity] = session;
		sessionsQuantity++;
		isAdded = 1;
	} else {
		Helpers::showMessage("��������� ������������ ���������� ������", 1);
	}

	return isAdded;
}

void Gradesbook::enterSession() {
	Session* session = new Session;
	string subjName;
	string subjMark;

	cin.ignore();

	for (int i = 0; i < 10; i++) {
		cout << i + 1 << ". ������� �������� ���������� (��� 0 ��� ������): ";
		getline(cin, subjName);

		if (subjName == "0") {
			break;
		}

		cout << "������� ������ (��� 0 ��� ������): ";
		getline(cin, subjMark);

		if (subjMark == "0") {
			break;
		}

		while (1) {
			int isError = 0;

			if (Helpers::validateInstitut(subjName) == "") {
				isError = 1;
				Helpers::showMessage("�������� �������� ����������", 2);
				cout << "���������� ��� ���: ";
				getline(cin, subjName);
			}
			else if (session->isSubjectExists(subjName) == 1) {
				isError = 1;
				Helpers::showMessage("����� ���������� ��� ������������ � ������ ������", 2);
				cout << "������� ������ ����������: ";
				getline(cin, subjName);
			}
			else {
				subjName = Helpers::trim(subjName);
			}

			if (!((int)Helpers::trim(subjMark)[0] > 48 && (int)Helpers::trim(subjMark)[0] < 54)) {
				isError = 1;
				Helpers::showMessage("�������� ������", 2);
				cout << "���������� ��� ���: ";
				getline(cin, subjMark);
			}

			if (!isError) {
				break;
			}
		}

		Subject* subject = new Subject(subjName, stoi(subjMark));
		session->addSubject(subject);
	}

	if (session->getSubjectsQuantity()) {
		addSession(session);
	}
}

void Gradesbook::freeSessions() {
	for (int i = 0; i < sessionsQuantity; i++) {
		for (int j = 0; j < sessions[i]->getSubjectsQuantity(); j++) {
			delete sessions[i]->getCertainSubject(j);
		}

		delete[] sessions[i];
	}
}

void Gradesbook::editSession() {
	string editSessionPoint = "-1";

	while (1) {
		int sessionsToEdit[10];
		int sessionsToEditQuantity = 0;
		cout << endl << "���������� � ����� ������ ����� ���������?" << endl;
		for (int i = 0; i < sessionsQuantity; i++) {
			if (sessions[i]->getSubjectsQuantity() < 10) {
				sessionsToEdit[sessionsToEditQuantity] = i;
				sessionsToEditQuantity++;
				cout << sessionsToEditQuantity << ". " << i + 1 << " ������" << endl;
			}
		}
		cout << "0. ��������� �����" << endl;
		cout << "����: ";
		cin >> editSessionPoint;

		if (Helpers::validateNumeric(Helpers::trim(editSessionPoint)) == "") {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}

		if (stoi(editSessionPoint) == 0) {
			return;
		}
		else if (!(stoi(editSessionPoint) > 0 && stoi(editSessionPoint) <= sessionsToEditQuantity)) {
			Helpers::showMessage("������ ������ ���", 2);
			continue;
		}
		string subjName;
		string subjMark;

		cin.ignore();

		for (int i = sessions[sessionsToEdit[stoi(editSessionPoint) - 1]]->getSubjectsQuantity(); i < 10; i++) {
			cout << i + 1 << ". ������� �������� ���������� (��� 0 ��� ������): ";
			getline(cin, subjName);

			if (Helpers::trim(subjName)[0] == '0') {
				break;
			}

			cout << "������� ������ (��� 0 ��� ������): ";
			getline(cin, subjMark);

			if (Helpers::trim(subjMark)[0] == '0') {
				break;
			}

			while (1) {
				int isError = 0;

				if (Helpers::validateInstitut(subjName) == "") {
					isError = 1;
					Helpers::showMessage("�������� �������� ����������", 2);
					cout << "���������� ��� ���: ";
					getline(cin, subjName);
				}
				else if (sessions[sessionsToEdit[stoi(editSessionPoint) - 1]]->isSubjectExists(subjName) == 1) {
					isError = 1;
					Helpers::showMessage("����� ���������� ��� ������������ � ������ ������", 2);
					cout << "������� ������ ����������: ";
					getline(cin, subjName);
				}
				else {
					subjName = Helpers::trim(subjName);
				}

				if (!((int)Helpers::trim(subjMark)[0] > 48 && (int)Helpers::trim(subjMark)[0] < 54)) {
					isError = 1;
					Helpers::showMessage("�������� ������", 2);
					cout << "���������� ��� ���: ";
					getline(cin, subjMark);
				}

				if (!isError) {
					break;
				}
			}

			Subject* subject = new Subject(subjName, stoi(subjMark));
			sessions[sessionsToEdit[stoi(editSessionPoint) - 1]]->addSubject(subject);
		}
	}
}