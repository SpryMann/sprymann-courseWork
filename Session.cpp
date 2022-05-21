#include "Session.h"
#include "Helpers.h"
#include "Subject.h"

int Session::getSubjectsQuantity() {
	return subjectsCurrentQuantity;
}

Subject* Session::getCertainSubject(int num) {
	if (num > getSubjectsQuantity()) {
		return NULL;
	}

	return subjects[num];
}

int Session::addSubject(Subject* subject) {
	int isAdded = 0;

	if (getSubjectsQuantity() != 10) {
		subjects[getSubjectsQuantity()] = subject;
		subjectsCurrentQuantity++;
		isAdded = 1;
	} else {
		Helpers::showMessage("В данном семестре уже записаны 10 дисциплин", 1);
	}

	return isAdded;
}

int Session::isSubjectExists(string subjectName) {
	int isExists = 0;

	for (int i = 0; i < getSubjectsQuantity(); i++) {
		if (Helpers::toLowerCase(subjectName) == Helpers::toLowerCase((*subjects[i]).name)) {
			isExists = 1;
		}
	}

	return isExists;
}