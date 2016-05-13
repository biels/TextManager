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
		const string mls = "afegir text"; //Multi line special command
		if (cmd.length() >= mls.length() && cmd.substr(0, mls.length()) == mls) {
			string lin;
			while(true){
				getline(cin, lin);
				if(lin == "****")break;
				cmd += '\n' + lin;
			}
		}
		if(cmd == "sortir")break;
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
	//bool forceBreak = false;
	vector<string> args_s;
	vector<int> args_i;
	int i = 0;
	while (iss >> s){
		// ? ending handling
		if(s == "?"){ // ? endings
			question = true;
			break;
		}
		//Parse string and int (?) args

		string delim0 = "\"{(“";
		string delim1 = "\"})”";
		bool begins_delim = false;
		unsigned int d_i = 0;
		while(d_i < delim0.size()){
			if(s[0] == delim0[d_i]){
				begins_delim = true;
				break;
			}
			d_i++;
		}
		bool is_keyword = !begins_delim;

		// TODO Handle unbounded string args based on numberof args_s (afegir text...) (set is_keyword to false)


		if (is_keyword) {
			//Is keyword
			keywords.push_back(s);
			continue;
		}else{
			//Is string arg beginning with delim0[d_i]
			string arg_s = s;
			while(s[s.length()-1] != delim1[d_i] || s == "****"){
				iss >> s;
				arg_s += " " + s;
			}
			args_s.push_back(arg_s);
		}

		//Forced exit conditions
		if(i >= 1){
			if(keywords[1] == "text"){
				string k0 = keywords[0];
				if (k0 == "eliminar")break; // eliminar text
				if (k0 == "triar" && args_s.size() > 0)break;
			}
			if(keywords[1] == "substitueix" && args_s.size() > 1)break; //substitueix
		}
		op.push_back(s);
		i++;
	}
	executeCommand(keywords, question, args_s, args_i);
}
void CommandExecutor::executeCommand(vector<string> keywords, bool question, vector<string> args_s, vector<int> args_i) {
	//Test display
	cout << "keywords(" << keywords.size() << "):";
	for(string s : keywords)cout << " [" << s << "]";
	cout << endl << "args_s(" << args_s.size() << "):";
	for(string s : args_s)cout << " [" << s << "]";
	cout << endl << "question: " << (question ? "yes" : "no") << endl;
	//Command execution - single context
	if(question && keywords[0] == "frases"){
		//frases x y ?
		if(keywords.size() == 3){
			int x, y;
			x = atoi(keywords[1].c_str());
			y = atoi(keywords[2].c_str());
			cout << x + 1 << y + 1;
			//a.frases(x, y);
			return;
		}
		//frases "" ?
		if(keywords.size() == 2){
			//starts with...
		}
	}
}


