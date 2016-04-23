/*
 * CommandExecutor.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "CommandExecutor.h"
#include <sstream>
#include <iostream>

#include "../Logic/Actions/ActionHandler.h"
using namespace std;

CommandExecutor::CommandExecutor(){

}

CommandExecutor::~CommandExecutor() {
	// TODO Auto-generated destructor stub
}


void CommandExecutor::readConsole() {
	string cmd;
	while(true){
		getline(cin, cmd);
		if(cmd == "end")break;
		executeCommand(cmd);
	}
}
void CommandExecutor::executeCommand(string cmd){
	string s;
	istringstream iss (cmd);
	vector<string> op;
	while (iss >> s) op.push_back(s);
	executeCommand(op);
}
void CommandExecutor::executeCommand(vector<string> args) {
	cout << "Cmd executed: " << args[0] << endl;
}
