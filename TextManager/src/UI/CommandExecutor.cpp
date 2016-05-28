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
		cout << cmd << endl;
		if(cmd == "")continue;
		const string mls = "afegir text"; //Multi line special command
		if (cmd.length() >= mls.length() && cmd.substr(0, mls.length()) == mls) {
			string lin;
			while(true){
				getline(cin, lin);
				if(lin == "")continue;
				cmd += '\n' + lin;
				if(lin == "****")break;
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
		//Parse string args
		//(({aa bb}) | {cc dd})
		string delim0 = "\"{(“"; //TODO contar parentesis
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
		if(i > 1 && keywords.size() > 1 && keywords[0] == "afegir" && keywords[1] == "text" && args_s.size() >= 2){
			is_keyword = false;
		}

		if (is_keyword) {
			//Is keyword
			keywords.push_back(s);
			continue;
		}
		else{
			//Is string arg beginning with delim0[d_i]
			string arg_s = s;
			while(s[s.length()-1] != delim1[d_i] || (d_i== 2)){
				iss >> s;
				if(s == "?" || s == "****")break; //(()) ? handling
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
	executeCommand(keywords, question, args_s);
	//cout << ">> End of command execution" << endl;
}

void CommandExecutor::executeCommand(vector<string> keywords, bool question, vector<string> args) {
	//Test display
//	cout << "keywords(" << keywords.size() << "):";
//	for(string s : keywords)cout << " [" << s << "]";
//	cout << endl << "args_s(" << args.size() << "):";
//	for(string s : args)cout << " [" << s << "]";
//	cout << endl << "question: " << (question ? "yes" : "no") << endl;
	//Command execution - single context

	if (keywords[0] == "frases"){
		//frases x y ?
		if(keywords.size() == 3){
			if(!isdigit(keywords[1][0]) || !isdigit(keywords[2][0])){
				cout << "error";
				return;
			}
			int x = atoi(keywords[1].c_str());
			int y = atoi(keywords[2].c_str());
			a.frases(x, y);
			return;
		}
		//frases ".." ? i frases <..> ?
		if(keywords.size() == 1) {
			//frases <..> ? (sequencia)
			if (args[0][0] == '"') {
				a.frasesSequencia(args[0]);
				return;
			}
			//frases ".." ? (expressió)
			else {
				a.frasesExpressio(args[0]);
				return;
			}
		}
	}
	if (question && keywords[0] == "tots") {
		//tots textos ?
		if (keywords[1] == "textos") {
			a.textos();
			return ;
		}
		//tots autors ?
		else {
			a.autors();
			return;
		}
	}
	if (question && keywords[0] == "nombre") {
		//nombre de frases ?
		if (keywords[2] == "frases") {
			a.nombreFrases();
			return;
		}
		//nombre de paraules ?
		if (keywords[2] == "paraules") {
			a.nombreParaules();
			return;
		}
	}
	//info ? i info cita "<referència>" ?
	if (question && keywords[0] == "info") {
		//info ?
		if (keywords.size() == 1) {
			a.info();
			return;
		}
		//info cita "<referència>" ?
		else {
			string ref = args[0].substr(1, args[0].length()-2);
			a.frasesExpressio(ref);
			return;
		}
	}
	//textos autor ?
	if (question && keywords[0] == "textos") {
		string autor = args[0].substr(1, args[0].length()-2);
		a.textosAutor(autor);
		return;
	}
	//autor ?
	if (question && keywords[0] == "autor") {
		a.autor();
		return;
	}
	//contingut ?
	if (question && keywords[0] == "contingut") {
		a.contingut();
		return;
	}
	//taula de frequencies ?
	if (question && keywords[0] == "taula") {
		a.taulaFrequencies();
		return;
	}
	//cites autor "<autor>" ? i cites ?
	if (question && keywords[0] == "cites") {
		//cites ?
		if (keywords.size() == 1) {
			a.cites();
			return;
		}
		//cites autor "<autor>"
		else {
			string autor = args[0].substr(1, args[0].length()-2);
			a.citesAutor(autor);
			return;
		}
	}
	//totes cites ?
	if (question && keywords[0] == "totes") {
		a.totesCites();
		return;
	}
	if (!question && keywords[0] == "eliminar") {
		//eliminar text
		if (keywords[1] == "text") {
			a.eliminarText();
			return;
		}
		//eliminar cita
		else {
			string ref = args[0].substr(1, args[0].length()-2);
			a.eliminarCita(ref);
			return;
		}
	}
	if (!question && keywords[0] == "afegir") {
		//Afegir text
		if (keywords[1] == "text") {
			string titol = args[0].substr(1, args[0].length()-2);
			string autor = args[1].substr(1, args[1].length()-2);
			a.afegirText(titol, autor, args[2]);
			return;
		}
		//afegir cita x y ?
		else {
			int x = atoi(keywords[2].c_str());
			int y = atoi(keywords[3].c_str());
			a.afegirCita(x, y);
			return;
		}
	}
	//triar text
	if (!question && keywords[0] == "triar") {
		a.triarText(args[0]);
		return;
	}
	//subtitueix “<paraula>” per “<paraula2>”
	if (!question && keywords[0] == "substitueix") {
		string s = args[0].substr(1, args[0].length()-2);
		string t = args[1].substr(1, args[1].length()-2);
		a.substitueix(s, t);
		return;
	}
}



