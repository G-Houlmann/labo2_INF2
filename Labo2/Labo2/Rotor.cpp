#include "Rotor.h"


Rotor::Rotor() : id(0), notch('a'), wiring(""), position(0){

}

Rotor::Rotor(const unsigned id, const char notch, const std::string wiring, char position) : id(id), notch(toupper(notch) - 65), wiring(wiring)
{
	this->position = toupper(position) - 65;
}

char Rotor::rToL(char c) {
	return wiring.at((position + c - 65) % 26);
}

char Rotor::lToR(char c) {
	char newC = wiring.find_first_of(c);
	if (position > newC) newC += 26;
	newC -= position;
	return newC + 65;
}

bool Rotor::rotation()
{
	bool nextRotorRotate = position == notch;
	position = (position + 1) % 26;
	return nextRotorRotate;
}

unsigned Rotor::getNotch() const{
	return notch;
}

unsigned Rotor::getPosition() const {
	return position;
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


