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
#include "../Logic/Actions/DataStructures/ConditionalExpression.h"

/**@class CommandExecutor
 * @brief Interpreta les comandes que entren pel canal d'entrada estàndar.
 * Aquesta classe s'encarrega únicament de processar la entrada i cridar les accions corresponents a l'ActionHandler.
 */

class CommandExecutor {
private:
	ActionHandler a;
	void executeCommand(string args);
	void executeCommand(vector<string> keywords, bool question, vector<string> args_s);
	static ConditionalExpression parseConditionalExpression(string expr);

public:
	/**
	 * @brief Creadora per defecte
	 * \pre Cert
	 * \post El resultat és un CommandExecutor nou
	 */
	CommandExecutor();

	/**
	 * @brief Destructora per defecte
	 */
	virtual ~CommandExecutor();

	/**@brief Llegeix el canal d'entrada estàndar.
	 * \pre Cert
	 * \post El programa finalitzarà la seva execució, perquè l'usuari ho ha demanat.
	 */
	void readConsole();

};

#endif /* UI_COMMANDEXECUTOR_H_ */
