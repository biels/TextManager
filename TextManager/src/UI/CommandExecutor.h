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
 * @brief Interpreta les comandes que entren pel canal d'entrada estàndar.
 * Aquesta classe s'encarrega únicament de processar l'entrada i cridar les accions corresponents a l'ActionHandler.
 */

class CommandExecutor {
private:
	ActionHandler a;
	/** @brief Executa la comanda especificada
	 * \pre args és una comanda amb format vàlid
	 * \post La comanda s'ha executat
	 */
	void executeCommand(string args);

	/**@brief Executa una comanda a partir de les paraules clau i els arguments.
	 * \pre Les paraules clau són reconegudes per l'especificació del sistema i els arguments es troben entre delimitadors.
	 * \post La comanda s'ha executat
	 * @param keywords Paraules clau de la comanda
	 * @param question Cert si la comanda acaba amb ?
	 * @param args_s Arguments de la comanda amb delimitadors
	 */
	void executeCommand(vector<string> keywords, bool question, vector<string> args_s);

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

	/**@brief Llegeix el canal d'entrada estàndard i executa les comandes que hi entrin.
	 * \pre Cert
	 * \post El programa finalitzarà la seva execució, perquè l'usuari ho ha demanat.
	 */
	void readConsole();

};

#endif /* UI_COMMANDEXECUTOR_H_ */
