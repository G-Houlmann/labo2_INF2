/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Enigma.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Permet de crï¿½er et de gï¿½rer une machine Enigma pour dï¿½coder 
			   des messages.

 Remarque(s) :

 Compilateur : g++ 6.3 
 -----------------------------------------------------------------------------------
 */

#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>
#include "Rotor.h"
#include "Reflector.h"


class Enigma
{
public:
	Enigma(const Rotor& leftRotor, const Rotor& middleRotor, 
               const Rotor& rightRotor, const Reflector& reflector);
	~Enigma();

	// DÃ©chiffre un caractÃ¨re. 
	// Le bool b permet l'affichage du "dÃ©bug", il est reprit du decode de 
        //string
	char decode(char c, bool b);

	// DÃ©chiffre une chaÃ®ne caractÃ¨re par caractÃ¨re. 
	// Le bool b permet l'affichage du "dÃ©bug"
	std::string decode(const std::string& s, bool b);

	//Position: 0 = right, 1 = middle, 2 = left
	void setRotor(const Rotor& rotor, unsigned position);

	void setReflector(Reflector reflector);

private:
	Rotor rotors[3];
	Reflector reflector;
};

#endif // !ENIGMA_H



