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
	void setRightRotor(Rotor Rotor);
	void setMiddleRotor(Rotor Rotor);
	void setLeftRotor(Rotor Rotor);
	void setReflector(Reflector reflector);

private:
	Rotor rotors[3];
	Reflector reflector;
};

#endif // !ENIGMA_H



