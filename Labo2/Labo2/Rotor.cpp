#include "Rotor.h"


Rotor::Rotor() : id(0), notch('a'), wiring(""){

}

Rotor::Rotor(const unsigned id, const unsigned notch, const std::string wiring, unsigned position) : id(id), notch(notch), wiring(wiring)
{
	position = toupper(position);
	this->position = position - 65;
}

char Rotor::rToL(char c) {
	return wiring.at((position + c - 65) % 26);
}

char Rotor::lToR(char c) {
	return wiring.at((position - c - 65) % 26);
}

void Rotor::rotation()
{
	position = (position + 1) % 26;
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


