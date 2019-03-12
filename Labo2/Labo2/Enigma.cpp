#include "Enigma.h"
#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

Enigma::Enigma(const Rotor& leftRotor, const Rotor& middleRotor, const Rotor& rightRotor, const Reflector& reflector) : reflector(reflector)
{
	rotors[0] = rightRotor;
	rotors[1] = middleRotor;
	rotors[2] = leftRotor;
}


Enigma::~Enigma()
{
}

const unsigned ROTORS_AMOUNT = 3;

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

std::string Enigma::decode(std::string s) {
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	string newS = s;

	//Decoding char by char
	char c;
	for (size_t i = 0; i < s.size(); ++i) {
		c = s[i];
		newS[i] = this->decode(c);
	}
	return newS;
}

void Enigma::setRotor(const Rotor& rotor, unsigned position) {
	rotors[position] = rotor;
}

void Enigma::setReflector(Reflector reflector) {
	this->reflector = reflector;
}
