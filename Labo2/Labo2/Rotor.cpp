/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Rotor.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Fichier source de Rotor.h

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#include "Rotor.h"

const int CHAR_SHIFT = 65;
const unsigned ALPHABET_LENGTH = 26;

Rotor::Rotor() : id(0), notch('a'), wiring(""), position(0){

}

Rotor::Rotor(const unsigned id, const char notch, const std::string wiring, 
        char position) : id(id), notch(toupper(notch) - CHAR_SHIFT), wiring(wiring)
{
	this->position = toupper(position) - CHAR_SHIFT;
}

char Rotor::rToL(char c) {
	return wiring.at((position + c - CHAR_SHIFT) % ALPHABET_LENGTH);
}

char Rotor::lToR(char c) {
	c = (char)wiring.find_first_of(c);
	if (position > (unsigned)c) c += ALPHABET_LENGTH;
	c -= position;
	return c + CHAR_SHIFT;
}

bool Rotor::rotation()
{
	bool nextRotorRotate = position == notch;
	position = (position + 1) % ALPHABET_LENGTH;
	return nextRotorRotate;
}


Rotor& Rotor::operator=(const Rotor& rotor) {
	if (this != &rotor) {
		(unsigned&)id = rotor.id;
		(unsigned&)notch = rotor.notch;
		(std::string&)wiring = rotor.wiring;
		position = rotor.position;
	}
	return *this;
}


Rotor::~Rotor(){}


