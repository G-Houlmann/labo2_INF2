#include "Reflector.h"

Reflector::Reflector() {

}

Reflector::Reflector(const std::string& name, const std::string& wiring) : name(name), wiring(wiring){

}


Reflector::~Reflector()
{
}

char Reflector::convert(char c) const {
	return this->wiring[c - 65];
}