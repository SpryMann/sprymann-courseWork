#include "Menu.h"
#include "File.h"
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;

int main() {
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  if (File::isFileExists("data.enc")) {
	  File::decrypt();
  }

  Menu menu;
  menu.mainMenu();

  if (File::isFileExists("data.dat")) {
	  File::encrypt();
  }

  return 0;
}
