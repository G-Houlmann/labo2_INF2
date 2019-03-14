/*
 -----------------------------------------------------------------------------------
 Laboratoire : 02
 Fichier     : Enigma.cpp
 Auteur(s)   : LAMRANI Soulaymane, HOULMANN Gildas
 Date        : 14.03.2019

But          : Ficher source de Enigma.h

 Remarque(s) :

 Compilateur : g++ 6.3
 -----------------------------------------------------------------------------------
 */

#include "Enigma.h"
#include <iostream>

using namespace std;

const unsigned ROTORS_AMOUNT = 3;

Enigma::Enigma(const Rotor& leftRotor, const Rotor& middleRotor, 
        const Rotor& rightRotor, const Reflector& reflector) : reflector(reflector)
{
	rotors[0] = rightRotor;
	rotors[1] = middleRotor;
	rotors[2] = leftRotor;

	cout << "----------------------------" << endl << "Enigma machine - Transmitter"
		<< endl << "----------------------------" << endl;
	string positions[] = { "LEFT", "MIDDLE", "RIGHT" };
	for (size_t i = 0; i < ROTORS_AMOUNT; ++i) {
		rotors[i].displayRotor(positions[i]);
	}
	reflector.displayReflector();
}

Enigma::~Enigma()
{
}

char Enigma::decode(char c, bool b) {
	c = (char)toupper(c);

	//Rotate rotors
	if (rotors[0].rotation()) {
		if (rotors[1].rotation()) {
			rotors[2].rotation();
		}
	}
	//Going through the rotors from left to right (0 to last)
	for (size_t i = 0; i < ROTORS_AMOUNT; ++i) {
		c = rotors[i].rToL(c, b);
	}
	//Going through reflector
	c = reflector.convert(c, b);
	//Going through the rotors from right to left (last to 0)
	for (size_t i = ROTORS_AMOUNT; i > 0; --i) {
		c = rotors[i-1].lToR(c, b);
	}
	return c;
}

std::string Enigma::decode(const std::string& s, bool b) {
	string newS = s; //New string containing decoded message

	//Decoding char by char
	for (size_t i = 0; i < s.size(); ++i) {
		newS[i] = this->decode(s[i], b);
		if (b) cout << "---------------NEW LETTER---------------" << endl;
	}
	return newS;
}

void Enigma::setRotor(const Rotor& rotor, unsigned position) {
	rotors[position] = rotor;
}

void Enigma::setReflector(Reflector reflector) {
	this->reflector = reflector;
}
