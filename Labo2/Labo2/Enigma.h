#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <string>
#include "Rotor.h"
#include "Reflector.h"


class Enigma
{
public:
	Enigma(const Rotor& leftRotor, const Rotor& middleRotor, const Rotor& rightRotor, const Reflector& reflector);
	~Enigma();
	char decode(char c);
	std::string decode(std::string s);
	void setRotor(const Rotor& rotor, unsigned position);
	void setReflector(Reflector reflector);

private:
	Rotor rotors[3];
	//Rotor rightRotor;
	//Rotor middleRotor;
	//Rotor leftRotor;
	Reflector reflector;
};

#endif // !ENIGMA_H



