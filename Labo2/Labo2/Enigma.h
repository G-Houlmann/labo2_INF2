#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <string>
#include "Rotor.h"
#include "Reflector.h"


class Enigma
{
public:
	Enigma();
	~Enigma();
	char decode(char c) const;
	std::string decode(std::string s) const;
	void setRotor(Rotor rotor, unsigned position);
	void setReflector(Reflector reflector);

private:
	Rotor* rotors[3];
	Reflector reflector;
};

#endif // !ENIGMA_H



