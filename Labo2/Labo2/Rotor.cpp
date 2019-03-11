#include "Rotor.h"



Rotor::Rotor(unsigned id, const char notch, const std::string baseWiring)
{
	this->id = id;
	this->nothc = notch;
	this->baseWiring = baseWiring;
}

void Rotor::rotation(std::string currentWiring)
{
	std::rotate(currentWiring.begin(), currentWiring.begin() + 1, currentWiring.end());
}

Rotor::~Rotor(){}
