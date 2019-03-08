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

char Enigma::decode(char c) const {
	c = toupper(c);
	return 'a';
}

std::string Enigma::decode(std::string s) const {
	transform(s.begin(), s.end(), s.begin(), ::toupper);

	return s;
}

void Enigma::setRotor(Rotor rotor, unsigned position) {
	rotors[position] = rotor;
}

void Enigma::setReflector(Reflector reflector) {
	this->reflector = reflector;
}
