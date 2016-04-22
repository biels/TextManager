//============================================================================
// Name        : TextManager.cpp
// Author      : Biel i Alba
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	TextSet s;
	ActionHandler a(s);
	CommandExecutor c(a);
	c.readConsole();
	return 0;
}
