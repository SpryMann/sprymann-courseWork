#include "Subject.h"

Subject::Subject() {
	mark = 0;
}

Subject::Subject(string subjectName, int markValue) {
	name = subjectName;
	mark = markValue;
}

string Subject::getSubjectName() {
	return name;
}

int Subject::getSubjectMark() {
	return mark;
}