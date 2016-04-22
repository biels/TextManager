/*
 * CommandExecutor.h
 *
 *  Created on: 22 abr. 2016
 *      Author: Biel
 */

#ifndef UI_COMMANDEXECUTOR_H_
#define UI_COMMANDEXECUTOR_H_
using namespace std;
#include <vector>
#include <string>
class CommandExecutor {
private:
	void executeCommand(vector<string> args);
public:
	CommandExecutor();
	virtual ~CommandExecutor();
	void readConsole();

};

#endif /* UI_COMMANDEXECUTOR_H_ */
