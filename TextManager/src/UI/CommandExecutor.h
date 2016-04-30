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
#include "../Logic/Actions/ActionHandler.h"

/**@class CommandExecutor
 * @brief Interpreta les comandes que entren pel canal d'entrada est�ndar
 * Aquesta classe s'encarrega �nicament de processar la entrada i cridar les accions corresponents a l'ActionHandler
 */
class CommandExecutor {
private:
	ActionHandler a;
	void executeCommand(string args);
	void executeCommand(vector<string> args);
public:
	CommandExecutor();

	virtual ~CommandExecutor();

	/**@brief Llegeix el canal d'entrada est�ndar
	 * \post El porgrama finalitzar� la seva execuci�, perqu� l'usuari ho ha demanat
	 */
	void readConsole();

};

#endif /* UI_COMMANDEXECUTOR_H_ */
