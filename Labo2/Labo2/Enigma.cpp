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
	string positions[] = { "LEFT", "MIDDLE", "RIGHT" };
	for (size_t i = 0; i < ROTORS_AMOUNT; ++i) {
		rotors[i].displayRotor(positions[i]);
	}
}

Enigma::~Enigma()
{
}

char Enigma::decode(char c) {
	c = toupper(c);

	//Rotate rotors
	if (rotors[0].rotation()) {
		if (rotors[1].rotation()) {
			rotors[2].rotation();
		}
	}
	//Going through the rotors from left to right (0 to last)
	for (size_t i = 0; i < ROTORS_AMOUNT; ++i) {
		c = rotors[i].rToL(c);
	}
	//Going through reflector
	c = reflector.convert(c);
	//Going through the rotors from right to left (last to 0)
	for (size_t i = ROTORS_AMOUNT; i > 0; --i) {
		c = rotors[i-1].lToR(c);
	}
	return c;
}

std::string Enigma::decode(const std::string& s) {
	string newS = s; //New string containing decoded message

	//Decoding char by char
	for (size_t i = 0; i < s.size(); ++i) {
		newS[i] = this->decode(s[i]);
	}
	return newS;
}

void Enigma::setRotor(const Rotor& rotor, unsigned position) {
	rotors[position] = rotor;
}

void Enigma::setReflector(Reflector reflector) {
	this->reflector = reflector;
}
