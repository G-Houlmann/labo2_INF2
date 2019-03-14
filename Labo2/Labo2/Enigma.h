/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Enigma.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Permet de créer et de gérer une machine Enigma pour décoder 
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

	// Déchiffre un caractère. 
	// Le bool b permet l'affichage du "debug", il est repris du decode(string)
	char decode(char c, bool b);

	// Déchiffre une chaîne caractère par caractère. 
	// Le bool b permet l'affichage du "debug"
	std::string decode(const std::string& s, bool b);

	//Position: 0 = right, 1 = middle, 2 = left
	void setRotor(const Rotor& rotor, unsigned position);

	void setReflector(Reflector reflector);

private:
	Rotor rotors[3];
	Reflector reflector;
};

#endif // !ENIGMA_H



