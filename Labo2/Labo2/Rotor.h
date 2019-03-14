/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Rotor.h
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Permet de cr�er et de g�rer un rotor convertissant une lettre en 
       	       une autre. Permet aussi de tourner un rotor et d'indiquer 
 *             si le prochain rotor doit tourner en fonction du Notch.

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#ifndef ROTOR_H
#define ROTOR_H

#include <string>
#include <algorithm>

class Rotor
{
public:
	Rotor();
	Rotor(const unsigned id, const char notch, const std::string wiring, 
              char position);

	char rToL(char c); // Go through the rotor from the right to the left
	char lToR(char c); // Go through the rotor from the left to the right

	//Rotate the wiring by 1 to the right.
	//Returns if the next rotor should rotate or not
	bool rotation();

	Rotor& operator=(const Rotor& rotor);
	~Rotor();

private:
	const unsigned id;
	const unsigned notch;
	const std::string wiring;
	unsigned position;
};

#endif //ROTOR_H
