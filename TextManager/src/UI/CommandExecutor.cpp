/*
 * CommandExecutor.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "CommandExecutor.h"
#include <sstream>
#include <iostream>
using namespace std;

CommandExecutor::CommandExecutor(ActionHandler a) {
	// TODO Auto-generated constructor stub

}

CommandExecutor::~CommandExecutor() {
	// TODO Auto-generated destructor stub
}


void CommandExecutor::readConsole() {
	string s;
	getline(cin, s);
	istringstream iss (s);
	vector<string> op;
	while (iss >> s) op.push_back(s);
	executeCommand(op);
}

void CommandExecutor::executeCommand(vector<string> args) {

}
