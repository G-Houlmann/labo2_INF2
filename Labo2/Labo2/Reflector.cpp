#include "Reflector.h"

Reflector::Reflector() {

}

Reflector::Reflector(const std::string& name, const std::string& wiring) : name(name), wiring(wiring){

}


Reflector::~Reflector()
{
}

Reflector& Reflector::operator=(const Reflector& reflector) {
	if (this != &reflector) {
		(std::string&)name = reflector.name;
		(std::string&)wiring = reflector.wiring;
	}
	return *this;
}

char Reflector::convert(char c) const {
	return this->wiring[c - 65];
}