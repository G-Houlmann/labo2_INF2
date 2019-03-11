#include "Enigma.h"
#include <algorithm>
#include <cctype>

using namespace std;

Enigma::Enigma()
{
}


Enigma::~Enigma()
{
}

const unsigned ROTORS_AMOUNT = 3;

char Enigma::decode(char c) const {
	char newC = toupper(c);
	size_t i = 0;

	for (; i < ROTORS_AMOUNT; ++i) {
		//Aller des rotors
	}
	newC = reflector.convert(newC);
	for (; i >= 0; --i) {
		//Retour des rotors
	}
	return newC;
}

std::string Enigma::decode(std::string s) const {
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	string newS = "";
	for (size_t i = 0; i < s.size(); ++i) {
		newS[i] = decode(s[i]);
	}
	return s;
}

//TODO faire passer uniquement l'adresse du rotor
void Enigma::setRotor(Rotor rotor, unsigned position) {
	rotors[position] = &rotor;
}

void Enigma::setReflector(Reflector reflector) {
	this->reflector = reflector;
}
