#pragma once
#include <string>

using namespace std;

class Helpers
{
	public:
		static string toLowerCase(string);
		static void showMessage(string, int);
		static int validateDay(int, int, int);
		static int validateMonth(string);
		static int validateYear(string);
		static int validateStartStudyYear(int, int);
		static string* validateDateString(string);
		static string trim(string);
		static string validateName(string);
		static string validateInstitut(string);
		static string validateSex(string);
		static string validateNumeric(string);
};

