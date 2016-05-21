//============================================================================
// Name        : TextManager.cpp
// Author      : Biel i Alba
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "UI/CommandExecutor.h"
using namespace std;

int main() {
	CommandExecutor c;
	cout << "Hello!" << endl;
	c.readConsole();
	cout << "See you soon!" << endl;
	return 0;
}
