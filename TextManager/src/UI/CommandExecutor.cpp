/*
 * CommandExecutor.cpp
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#include "CommandExecutor.h"
#include <sstream>
#include <iostream>
#include <string>
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
void CommandExecutor::executeCommand(string cmd){ //Això s'haurà de millorar
	string s;
	istringstream iss (cmd);
	vector<string> op;

	// IDEA: [keyword], "Multi-word argument string (args_s)", /x (int)/, {array}, (ConditionaExpression), trailing multi word string, ? -> question == true
	//EXAMPLE: [afegir] [text] "text with multiple words" [?]
	vector<string> keywords;
	bool question = false;
	bool forceBreak = false;
	vector<string> args_s;
	vector<int> args_i;
	int i = 0;
	while (iss >> s){
		if(i == 0 || s[0] != '"'){
			//Is keyword
			keywords.push_back(s);
			continue;
		}

		//Exit
		if(s == "?"){
			question = true;
			break;
		}
		if(i >= 2){
			if(keywords[1] == "text"){
				string k0 = keywords[0];
				if (k0 == "eliminar")break;

			}

		}
		op.push_back(s);
		i++;
	}
	executeCommand(keywords, question, args_s, args_i);
}
void CommandExecutor::executeCommand(vector<string> keywords, bool question, vector<string> args_s, vector<int> args_i) {
	cout << "keywords:";
	for(string s : keywords)cout << " " << s << endl;
	cout << "question:";

}


